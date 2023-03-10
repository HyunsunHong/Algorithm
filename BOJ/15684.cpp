/*
  
  gold 4
  
  implementation + backtracking + bruteforce
  
*/

#include <iostream>

using namespace std;

int N, M, H;
int intersection[32][11];
int ans = -1;

int dfs(int r, int c, bool is_down) {
    if(r == H + 1) return c;
    
    if(is_down || intersection[r][c] == 0) return dfs(r + 1, c, false);
    else return dfs(r, c + intersection[r][c], true);
}

bool go(int r, int c, int rest) {
    if(rest == 0) {
        for(int i = 1; i <= N; i++) {
            if(i != dfs(0, i, true)) return false;
        }
        return true;       
    }

    if(r == H + 1 && c == N - 1) return false;
    if(r > H) return go(1, c + 1, rest);
    
    if(intersection[r][c] != 0) return go(r + 1, c, rest);
    else {
        bool ret = go(r + 1, c, rest);
        if(ret) return true;
        
        if(intersection[r][c + 1] == 0) {
            intersection[r][c] = 1;
            intersection[r][c + 1] = -1;
            ret = go(r + 1, c, rest - 1);
            intersection[r][c] = 0;
            intersection[r][c + 1] = 0;
        }
        return ret;
    }
}

int main() {

    cin >> N >> M >> H;

    for(int i = 0; i < M; i++) {
        int a, b;

        cin >> a >> b;
        
        intersection[a][b] = 1;
        intersection[a][b + 1] = -1;
    }

    for(int i = 0; i < 4; i++) {
        if(go(1, 1, i)) {
            ans = i;
            break;
        }
    }
    
    cout << ans << "\n";

    return 0;
}
