/*
  
  gold 5
  
  bfs + implementation

*/

#include <iostream>
#include <vector>
#include <queue>
#define U 0
#define R 1
#define D 2
#define L 3

using namespace std;

char Map[1001][1001];
int n, m;
bool visited[1001][1001];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0 ,1, 0, -1};
vector<int> ans;

bool possible(int r, int c) {
    if(r < 1 || r > n) return false;
    if(c < 1 || c > m) return false;
    return true;
}

bool go(char curr, char next) {
    
}

void bfs(int r, int c) {
    queue<pair<int, int> > q;
    
    visited[r][c] = true;
    q.push(make_pair(r, c));

    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;

        q.pop();

        vector<int> dir_vec;

        if(Map[r][c] == 'B') {
            dir_vec.push_back(L);
            dir_vec.push_back(D);
        }
        else if(Map[r][c] == 'C') {
            dir_vec.push_back(L);
            dir_vec.push_back(U);
        }
        else if(Map[r][c] == 'D') {
            dir_vec.push_back(U);
            dir_vec.push_back(R);
        }
        else if(Map[r][c] == 'E') {
            dir_vec.push_back(R);
            dir_vec.push_back(D);
        }
        else if(Map[r][c] == 'F') {
            dir_vec.push_back(U);
            dir_vec.push_back(D);
            dir_vec.push_back(R);
            dir_vec.push_back(L);
        }

        for(auto d : dir_vec) {
            int next_r = r + dr[d];
            int next_c = c + dc[d];

            if(!possible(next_r, next_c) || visited[next_r][next_c]) continue;
            
            int next_grid = Map[next_r][next_c];
            if(d == U && (next_grid == 'B' || next_grid == 'E' || next_grid == 'F')) { 
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }
            else if(d == D && (next_grid == 'C' || next_grid == 'D' || next_grid == 'F')) {
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }
            else if(d == R && (next_grid == 'B' || next_grid == 'C' || next_grid == 'F')) {
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }
            else if(d == L && (next_grid == 'D' || next_grid == 'E' || next_grid == 'F')) {
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }
        }
    }
} 

void print_debug() {
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            if(visited[r][c]) cout << "T";
            else cout << "F";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

int main() {

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int T;

    cin >> T;

    while(T--) {
        int ret = 0;

        cin >> n >> m;

        vector<pair<int ,int> > grid_vec;
        
        for(int r = 1; r <= n; r++) {
            for(int c = 1; c <= m; c++) {
                cin >> Map[r][c];
                if(Map[r][c] != 'A') {
                    grid_vec.push_back(make_pair(r, c));
                }
                visited[r][c] = false;
            } 
        }

        for(auto p : grid_vec) {
            int r = p.first;
            int c = p.second;
            if(!visited[r][c]) {
                bfs(r, c);
                ret++;
            }
            //print_debug(); 
        }
        
        ans.push_back(ret);
    }

    for(auto a : ans) cout << a << "\n";

    return 0;
}
