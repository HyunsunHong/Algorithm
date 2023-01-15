/*

    gold 2

    implementation + simulation

    1. 말들의 위치 및 방향 정보를 위한 벡터 1개, 판의 각 좌표 위치별 말의 스택 정보를 위한 벡터 1개

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct chess {
    int r;
    int c;
    int d;

    chess(int R = 0, int C = 0, int D = 0) : r(R), c(C), d(D) {}
};

int N, K;
int board[13][13];
int dr[5] = {0, 0, 0, -1, 1};
int dc[5] = {0, 1, -1, 0, 0};
int ans = 0;
vector<chess> chesses(11);
vector<vector<vector<int> > > stack_state; 

bool possible(int r, int c) {
    if(r < 1 || r > N) return false;
    if(c < 1 || c > N) return false;

    return true;
}

int opposite(int dir) {
    if(dir == 1) return 2;
    if(dir == 2) return 1;
    if(dir == 3) return 4;

    return 3;
}

int main() {

    cin >> N >> K;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> board[r][c];
        }
    }
    for(int r = 0; r <= N; r++) {
        vector<vector<int> > vec(N + 1);
        stack_state.push_back(vec);
    }
    for(int i = 1; i <= K; i++) {
        int r, c, d;

        cin >> r >> c >> d;

        chesses[i] = chess(r, c, d);
        stack_state[r][c].push_back(i);
    }

    bool end = false;

    while(!end) {
        ans++;
        if(ans > 1000) {
            ans = -1;
            break;
        }

        for(int i = 1; i <= K; i++) {
            int r = chesses[i].r;
            int c = chesses[i].c;
            int d = chesses[i].d;
            int next_r = r + dr[d];
            int next_c = c + dc[d];

            if(stack_state[r][c].front() != i) continue;

            // blue or impossible case (modify d)
            if(!possible(next_r, next_c) || board[next_r][next_c] == 2) {
                d = opposite(d);
                chesses[i].d = d;
                
                next_r = r + dr[d];
                next_c = c + dc[d];
                if(!possible(next_r, next_c) || board[next_r][next_c] == 2) {
                    continue;
                }
            }

            // red
            if(board[next_r][next_c] == 1) reverse(stack_state[r][c].begin(), stack_state[r][c].end());

            for(auto x : stack_state[r][c]) {
                chesses[x].r = next_r;
                chesses[x].c = next_c;
                stack_state[next_r][next_c].push_back(x);
            }
            stack_state[r][c].clear(); 

            if(stack_state[next_r][next_c].size() >= 4) {
                end = true;
                break;
            }
        }  
    }

    cout << ans << "\n";

    return 0;
}