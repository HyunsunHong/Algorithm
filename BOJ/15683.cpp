/*

    gold 4

    implementation + bruteforce + simulation

    1. 각 cctv가 돌릴 수 있는 모든 방향 조합을 탐색해야한다.
    2. 각 cctv 방향에 따른 office map에서의 simulation은 모든 cctv의 방향이 확정되었을 때 하는 것이 아니라, 각 cctv의 방향이 확정 될때마다 수행하며, 이를 기반으로 다음 cctv를 탐색한다.
    -> time saving

*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct cctv {
    int r;
    int c;
    int type;  // 1 ~ 5

    cctv(int R, int C, int T) :  r(R), c(C), type(T) {}
};

int N, M;
int ans = 0;
int empty_cnt = 0;
vector<vector<int> > office(8);
vector<cctv> cctvs;
vector<cctv> five_cctvs;
int type_1_dr[4] = {0, 1, 0, -1};
int type_1_dc[4] = {1, 0 ,-1, 0};
int type_2_dr[2][2] = {{0, 0}, {1, -1}}; //[dir][side1 or side2]
int type_2_dc[2][2] = {{1, -1}, {0, 0}}; //[dir][side1 or side2]
int type_3_dr[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int type_3_dc[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int type_4_d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
int max_dir[6] = {0, 3, 1, 3, 3, 0};

bool possible(int r, int c) {
    if(r < 0 || r > N - 1) return false;
    if(c < 0 || c > M - 1) return false;
    return true;
}

void go(int idx, int ret) {
    if(idx == cctvs.size()) {
        ans = min(ans, ret);
        return;
    }

    for(int dir = 0; dir <= max_dir[cctvs[idx].type]; dir++) {
        vector<pair<int, int> > touched;

        int r = cctvs[idx].r;
        int c = cctvs[idx].c;
        int type = cctvs[idx].type; 

        if(type == 1) {
            int next_r = r + type_1_dr[dir];
            int next_c = c + type_1_dc[dir];
            while(possible(next_r, next_c) && office[next_r][next_c] != 6) {
                if(office[next_r][next_c] == 0) {
                    ret--;
                    office[next_r][next_c] = -1;
                    touched.push_back(make_pair(next_r, next_c));
                }
                next_r += type_1_dr[dir];
                next_c += type_1_dc[dir];
            } 
        }
        else if(type == 2) {
            int next_r[2] = {r, r};
            int next_c[2] = {c, c};

            for(int i = 0; i < 2; i++) {
                next_r[i] += type_2_dr[dir][i];
                next_c[i] += type_2_dc[dir][i];
                while(possible(next_r[i], next_c[i]) && office[next_r[i]][next_c[i]] != 6) {
                    if(office[next_r[i]][next_c[i]] == 0) {
                        ret--;
                        office[next_r[i]][next_c[i]] = -1;
                        touched.push_back(make_pair(next_r[i], next_c[i]));
                    }
                    next_r[i] += type_2_dr[dir][i];
                    next_c[i] += type_2_dc[dir][i];
                } 
            }
        }
        else if(type == 3) {
            int next_r[2] = {r, r};
            int next_c[2] = {c, c};

            for(int i = 0; i < 2; i++) {
                next_r[i] += type_3_dr[dir][i];
                next_c[i] += type_3_dc[dir][i];
                while(possible(next_r[i], next_c[i]) && office[next_r[i]][next_c[i]] != 6) {
                    if(office[next_r[i]][next_c[i]] == 0) {
                        ret--;
                        office[next_r[i]][next_c[i]] = -1;
                        touched.push_back(make_pair(next_r[i], next_c[i]));
                    }
                    next_r[i] += type_3_dr[dir][i];
                    next_c[i] += type_3_dc[dir][i];
                } 
            }
        }
        else if(type == 4) {
            for(int i = 0; i < 4; i++) {
                if(i == dir) continue;

                int next_r = r + type_4_d[i][0];
                int next_c = c + type_4_d[i][1];
                while(possible(next_r, next_c) && office[next_r][next_c] != 6) {
                    if(office[next_r][next_c] == 0) {
                        ret--;
                        office[next_r][next_c] = -1;
                        touched.push_back(make_pair(next_r, next_c));
                    }
                    next_r += type_4_d[i][0];
                    next_c += type_4_d[i][1];
                } 
            }
        }

        go(idx + 1, ret);

        ret += touched.size();
        for(auto p : touched) {
            office[p.first][p.second] = 0;
        }
    }
}

void five_cctvs_process() {
    for(auto it = five_cctvs.begin(); it != five_cctvs.end(); it++) {
        int r = it->r;
        int c = it->c;
        
        for(int i = 0; i < 4; i++) {
            int next_r = r + type_4_d[i][0];
            int next_c = c + type_4_d[i][1];
            while(possible(next_r, next_c) && office[next_r][next_c] != 6) {
                if(office[next_r][next_c] == 0) {
                    empty_cnt--;
                    office[next_r][next_c] = -1;
                }
                next_r += type_4_d[i][0];
                next_c += type_4_d[i][1];
            } 
        }  
    }
}

int main() {
    cin >> N >> M;

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            int input;

            cin >> input;

            office[r].push_back(input);

            if(1 <= input && input <= 4) cctvs.push_back(cctv(r, c, input));
            else if(input == 0) empty_cnt++;
            else if(input == 5) five_cctvs.push_back(cctv(r, c, input));
        }
    }   
    five_cctvs_process();

    ans = empty_cnt;

    go(0, ans);
    
    cout << ans << "\n";

    return 0;
}