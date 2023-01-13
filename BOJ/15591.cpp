/*

    gold 5

    dfs

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int INF = 987654321;
int N, Q;
vector<vector<pair<int, int> > > adj(5001);
vector<int> ans;

int dfs(int start, int k) {
    stack<pair<int, int> > s;
    int ret = 0;
    bool visited[5001] = {false, };

    s.push(make_pair(start, INF));
    visited[start] = true;

    while(!s.empty()) {
        int curr = s.top().first;
        int usado_cnt = s.top().second;
        s.pop();

        //cout << curr << "\n";

        for(int i = 0; i < adj[curr].size(); i++) {
            int next = adj[curr][i].first;
            if(visited[next]) continue;

            int next_usado = min(usado_cnt, adj[curr][i].second);
            if(next_usado >= k) {
                ret++;
                visited[next] = true;
                s.push(make_pair(next, next_usado));
            }
        }
    }

    return ret;
}

int main() {

    cin >> N >> Q;

    for(int i = 0; i < N - 1; i++) {
        int p, q, r;

        cin >> p >> q >> r;

        adj[p].push_back(make_pair(q, r));
        adj[q].push_back(make_pair(p, r));
    }

    for(int i = 0; i < Q; i++) {
        int k ,v;

        cin >> k >> v;

        ans.push_back(dfs(v, k));
    }

    for(auto x : ans) cout << x << "\n";


    return 0;
}