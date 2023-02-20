/*
  
  bfs
  
*/

#include <iostream>
#include <queue>

using namespace std;

int N, M, T;
bool is_obect[1001][1001];
bool visited[1001][1001];
int color[1001][1001][3];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int ans = 0;

void bfs(int r, int c) {
    queue<pair<int, int> > q;

    q.push(make_pair(r, c));
    visited[r][c] = true;

    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;

        q.pop();        

        for(int i = 0; i < 4; i++) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];

            if(next_r > 0 && next_r < N + 1 && next_c > 0 && next_c < M + 1 && !visited[next_r][next_c] && is_obect[next_r][next_c]) {
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }
        }
    }

}

int main() {

    cin >> N >> M;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= M; c++) {
            for(int i = 0; i < 3; i++) {
                cin >> color[r][c][i];
            }
        }
    }

    cin >> T;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= M; c++) {
            int sum = 0;
            for(int i = 0; i < 3; i++) {
                sum += color[r][c][i];
            }
            if(sum/3 >= T) is_obect[r][c] = true;
        }
    }
    

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= M; c++) {
            if(!visited[r][c] && is_obect[r][c]) {
                bfs(r, c);
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}
