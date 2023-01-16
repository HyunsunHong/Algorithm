/*

    platinum 5

    Union find + dfs + data structure

    1. 매 쿼리마다 N개를 초기화 하지 않고 K개를 초기화 하도록 하는 것이 핵심
    2. S에서 연결된 부분 집합과 그 원소의 갯수를 찾아서 조합 공식 이용
    3. 부분집합 찾을 때, S의 원소와 그 부모 노드가 S에 속하는지 파악 한 후 S에 속하면 Union하는 것이 핵심
    4. p값은 노드가 Union의 root이면 해당 Union의 원소의 갯수의 음수값, root가 아니면 해당 Union의 root를 가리키는 노드번호
    5. find를 통해 해당 노드의 Union의 root번호 얻음

*/

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

const int MAX = 250001;
int N, Q, K;
vector<vector<int> > adj(MAX);
vector<long long> ans;
vector<int> Kset;
int p[MAX], tp[MAX];
bool is_Kset[MAX] = {false, };

void dfs(int curr, int parent) {
    for(auto child : adj[curr]) {
        if(child == parent) continue;

        tp[child] = curr;
        dfs(child, curr);
    }
}

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    p[a] += p[b];
    p[b] = a;
}

int main() {
    
    cin >> N;

    for(int i = 0; i < N - 1; i++) {
        int u, v;

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    memset(p, -1, sizeof(p));

    cin >> Q;

    while(Q--) {
        long long ret = 0;
        cin >> K;

        for(int i = 0; i < K; i++) {
            int input;
            cin >> input;
            Kset.push_back(input);
            is_Kset[input] = true;
        }

        for(auto x : Kset) {
            if(is_Kset[tp[x]]) Union(x, tp[x]);
        }

        for(auto x : Kset) {
            if(p[x] < -1) {
                ret += 1LL*(-p[x])*(-p[x] - 1)/2;
            }
        }
        
        for(auto x : Kset) {
            is_Kset[x] = false;
            p[x] = -1;
        }

        Kset.clear();
        ans.push_back(ret);
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}