/*
  
  gold 5
  
  bfs 

*/

#include <iostream>
#include <queue>

using namespace std;

struct node{
    int l;
    int r;
    int c;
    int cnt;

    node(int L, int R, int C, int CNT) : l(L), r(R), c(C), cnt(CNT) {}
};

int L, R, C;
char building[31][31][31];
bool visited[31][31][31];
int sl, sr, sc;
int dl[6] = {0, 0, 0, 0, 1, -1};
int dr[6] = {1, -1, 0, 0, 0, 0};
int dc[6] = {0, 0, 1, -1, 0, 0};

bool possible(int l, int r, int c) {
    if(l < 1 || l > L) return false;
    if(r < 1 || r > R) return false;
    if(c < 1 || c > C) return false;

    return true;
}

int bfs() {
    queue<node> q;
    visited[sl][sr][sc] = true;
    q.push(node(sl, sr, sc, 0));

    while(!q.empty()) {
        int curr_l = q.front().l;
        int curr_r = q.front().r;
        int curr_c = q.front().c;
        int curr_cnt = q.front().cnt;

        q.pop();

        for(int i = 0; i < 6; i++) {
            int next_l = curr_l + dl[i];
            int next_r = curr_r + dr[i];
            int next_c = curr_c + dc[i];
            int next_cnt = curr_cnt + 1;
            
            if(!possible(next_l, next_r, next_c) || building[next_l][next_r][next_c] == '#' || visited[next_l][next_r][next_c]) continue;

            if(building[next_l][next_r][next_c] == 'E') return next_cnt;

            visited[next_l][next_r][next_c] = true;
            q.push(node(next_l, next_r, next_c, next_cnt));
        }
    }


    return -1;
}

int main() {

    while(true) {
        cin >> L >> R >> C;

        if(L == 0 && R == 0 && C == 0) break;

        for(int l = 1; l <= L; l++) {
            for(int r = 1; r <= R; r++) {
                for(int c = 1; c <= C; c++) {
                    cin >> building[l][r][c];
                    visited[l][r][c] = false;
                    if(building[l][r][c] == 'S') {
                        sl = l;
                        sr = r;
                        sc = c;
                    }                  
                }
            }
        }

        int ret = bfs();

        if(ret == -1) cout << "Trapped!\n";
        else cout << "Escaped in " << ret << " minute(s).\n"; 
    }

    return 0;
}
