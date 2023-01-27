/*
  gold 4
  
  mst with kruskal

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge {
    int a;
    int b;
    int d;

    edge(int A, int B, int D) : a(A), b(B), d(D) {}
};

int T;
int N, M;
int set[21];
vector<int> ans;

int parent(int x) {
    if(set[x] == x) return x;
    return set[x] = parent(set[x]);
}

void Union(int a, int b) {
    a = parent(a);
    b = parent(b);

    if(a < b) set[b] = a;
    else set[a] = b; 
}

bool is_Union(int a, int b) {
    return parent(a) == parent(b);
}

bool cmp(edge e1, edge e2) {
    return e1.d < e2.d;
}

int main() {

    cin >> T;  

    while(T--) {
        cin >> N >> M;

        vector<edge> vec;
        int ret = 0;

        for(int i = 1; i <= N; i++) {
            set[i] = i;
        }

        for(int i = 0; i < M; i++) {
            int a, b, d;

            cin >> a >> b >> d;

            vec.push_back(edge(a, b, d));
        }

        sort(vec.begin(), vec.end(), cmp);

        for(auto e : vec) {
            if(!is_Union(e.a, e.b)) {
                Union(e.a, e.b);
                ret += e.d;
            }
        }
        ans.push_back(ret);
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << "Case #" << i + 1 << ": " << ans[i] << " meters\n";
    }

    return 0;
}
