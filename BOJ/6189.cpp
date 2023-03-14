/*
  
  silver 5
  
  bfs

*/

#include <iostream>
#include <queue>

using namespace std;

int R, C;
bool visited[101][101];
char map[101][101];
int dr[4] = {0 ,0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int ans = 0;

bool possible(int r, int c) {
    if(r < 1 || r > R) return false;
    if(c < 1 || c > C) return false;
    return true;
}

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
            
            if(!possible(next_r, next_c) || visited[next_r][next_c] || map[next_r][next_c] != '#') continue;
            
            visited[next_r][next_c] = true;
            q.push(make_pair(next_r, next_c));
        }
    }
}

int main() {
    
    cin >> R >> C;
    
    for(int r = 1; r <= R; r++) {
        for(int c = 1; c <= C; c++) {
            cin >> map[r][c];
        }
    }
   
    for(int r = 1; r <= R; r++) {
        for(int c = 1; c <= C; c++) {
            if(!visited[r][c] && map[r][c] == '#') {
                ans++;
                bfs(r, c);
            }
        }
    }
       
    cout << ans << "\n";
    
    return 0;
}
