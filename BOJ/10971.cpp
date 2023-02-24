/*
  
  silver 2
  backtracking
  
*/

#include <iostream>
#include <vector>

using namespace std;

long long ans = 10000001;
bool visited[11];
int N;
long long adj[11][11];

void go(int curr, int start, long long dist_cnt, long long node_cnt) {
    for(int next = 1; next <= N; next++) {
        if((visited[next] && next != start) || adj[curr][next] == 0) continue;

        if(next == start && node_cnt == N) {
            ans = min(ans, dist_cnt + adj[curr][next]);
            break;
        }
        else if(next == start) continue;

        visited[next] = true;
        go(next, start, dist_cnt + adj[curr][next], node_cnt + 1);
        visited[next] = false;
    } 
}

void solve(int start) {
    visited[start] = true;
    go(start, start, 0, 1);    
    visited[start] = false;
}

int main() {

    cin >> N;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> adj[r][c];
        }
    }

    for(int i = 1; i <= N; i++) {
        solve(i);
    }

    cout << ans;

    return 0;
}
