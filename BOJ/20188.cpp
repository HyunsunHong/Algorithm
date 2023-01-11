/*

    platinum 5

    dp in tree + math + dfs

    1. 
    Assume parent is top.
    dp[parent][0] : sum of diversity 
    dp[parent][1] : # of nodes 
    dp[parent][2] : sum of distances of each child

    2.
    dp[parent][0] += dp[child][0] + Combination(dp[child][1], 2) // add paths only between child's children
    dp[parent][0] += (dp[child][2] + dp[child][1]) * (dp[parent][1] - dp[child][1]) // add paths between child and ohter's child

    dp[parent][1] += dp[child][1]

    dp[parent][2] += p[child][2] + dp[child][1] 
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<vector<int> > adj(300001);
long long dp[300001][3];
long long cache[300001][3];

long long combinatin(long long n, long long r) {
    if(n < r) return 0;
    if(n == r || r == 0) return 1;

    if(cache[n][r] != -1) return cache[n][r];

    return cache[n][r] = combinatin(n - 1, r - 1) + combinatin(n - 1, r);
}

void dfs(int curr, int parent) {
    dp[curr][1] = 1;

    for(int i = 0; i < adj[curr].size(); i++) {
        int next = adj[curr][i];
        if(next == parent) continue;
        
        dfs(next, curr);
    }

    for(int i = 0; i < adj[curr].size(); i++) {
        int next = adj[curr][i];
        if(next == parent) continue;

        dp[curr][1] += dp[next][1];
        dp[curr][2] += dp[next][2] + dp[next][1];
    }

    for(int i = 0; i < adj[curr].size(); i++) {
        int next = adj[curr][i];
        if(next == parent) continue;

        dp[curr][0] += dp[next][0] + combinatin(dp[next][1], 2);
        dp[curr][0] += (dp[next][2] + dp[next][1])*(dp[curr][1] - dp[next][1]);
    }
    
}

int main() {

    memset(dp, 0, sizeof(dp));
    memset(cache, -1, sizeof(cache));

    cin >> N;

    for(int i = 0; i < N - 1; i++) {
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    cout << dp[1][0] << "\n";

    return 0;
}