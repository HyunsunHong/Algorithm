/*
  
  silver 1
  
  bruteforce + backtracking + dfs

*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<string> map;
bool visited[5][5];
int R, C, K;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int ans = 0;

bool possible(int r, int c) {
    if(r < 0 || r > R - 1) return false;
    if(c < 0 || c > C - 1) return false;
    return true;
}

void dfs(int r, int c, int cnt) {
    if(r == 0 && c == C - 1) {
        if(cnt == K) ans++;

        return;
    }
    if(cnt > K) return;

    for(int i = 0; i < 4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];

        if(possible(next_r, next_c) && map[next_r][next_c] != 'T' && !visited[next_r][next_c]) {
            visited[next_r][next_c] = true;
            dfs(next_r, next_c, cnt + 1);
            visited[next_r][next_c] = false;
        }
    }
}


int main() {

    memset(visited, false, sizeof(visited));

    cin >> R >> C >> K;

    for(int i = 0; i < R; i++) {
        string input;
        cin >> input;

        map.push_back(input);
    }

    visited[R - 1][0] = true;
    dfs(R - 1, 0, 1);

    cout << ans << "\n";

    return 0;
}
