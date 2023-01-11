/*

    dfs

*/

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > adj(101);
int visited_cnt[101] = {0, };
int ans = -1;

void dfs(int curr) {
    
    visited_cnt[curr]++;

    for(int i = 0; i < adj[curr].size(); i++) {
        int next = adj[curr][i];

        dfs(next);
    }
}

int main() {

    cin >> N;

    for(int i = 0; i < N - 1; i++) {
        int u ,v;

        cin >> u >> v;

        adj[u].push_back(v);
    }

    for(int i = 1; i <= N; i++) dfs(i);

    for(int i = 1; i <= N; i++) {
        if(visited_cnt[i] == N && ans == -1) ans = i;
    }

    cout << ans << "\n";

    return 0;
}