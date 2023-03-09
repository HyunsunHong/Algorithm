/*
  
  gold 5
  
  implementation

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int r;
    int c;
    int like_cnt;
    int empty_cnt;
    
    node(int R, int C, int L, int E) : r(R), c(C), like_cnt(L), empty_cnt(E) {}
};

int N;
int map[21][21];
int student[401][5];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int std_to_idx[401];

bool cmp(node n1, node n2) {
    if(n1.like_cnt > n2.like_cnt) return true;
    else if(n1.like_cnt == n2.like_cnt) {
        if(n1.empty_cnt > n2.empty_cnt) return true;
        else if(n1.empty_cnt == n2.empty_cnt) {
            if(n1.r < n2.r) return true;
            else if(n1.r == n2.r) {
                if(n1.c < n2.c) return true;
                else false;
            }
            else return false;
        }
        else return false;
    }
    
    return false;
}

bool possible(int r, int c) {
    if(r < 1 || r > N) return false;
    if(c < 1 || c > N) return false;
    return true;
}

int like_cnt(int r, int c, int std) {
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        if(!possible(next_r, next_c) || map[next_r][next_c] == 0) continue;

        for(int j = 1; j < 5; j++) {
            if(map[next_r][next_c] == student[std_to_idx[std]][j]) {
                ret++;
                break;
            }
        }
    }
    return ret;
}

int empty_cnt(int r, int c) {
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];

        if(possible(next_r, next_c) && map[next_r][next_c] == 0) ret++;
    }
    return ret;
}

void insert(int std) {
    vector<node> vec;
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            if(map[r][c] == 0) {
                vec.push_back(node(r, c, like_cnt(r, c, std), empty_cnt(r, c)));
            }
        }
    }
    
    sort(vec.begin(), vec.end(), cmp);

    map[vec[0].r][vec[0].c] = std;
}

int get_satisfy(int r, int c) {
    int ret = 0;
    int std = map[r][c];
    for(int i = 0; i < 4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        if(!possible(next_r, next_c) || map[next_r][next_c] == 0) continue;

        for(int j = 1; j < 5; j++) {
            if(map[next_r][next_c] == student[std_to_idx[std]][j]) {
                ret++;
                break;
            }
        }
    }

    if(ret == 0) ret = 0;
    else if(ret == 1) ret = 1;
    else if(ret == 2) ret = 10;
    else if(ret == 3) ret = 100;
    else if(ret == 4) ret = 1000;

    return ret;
}


int main() {

    cin >> N;

    int ans = 0;

    for(int i = 1; i <= N*N; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> student[i][j];
        }
        std_to_idx[student[i][0]] = i;
        insert(student[i][0]);
    }

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            ans += get_satisfy(r, c);
        }
    }

    cout << ans << "\n";

    return 0;
}
