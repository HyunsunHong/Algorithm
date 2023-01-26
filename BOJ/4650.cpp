/*

  gold 4
  
  kruskal algorithm

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int a;
    int b;
    int d;

    edge(int A, int B, int D) : a(A), b(B), d(D) {}
};

int N, K;
vector<edge> edge_vec;
int set[26] = {0, };
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

bool cmp(edge a, edge b) {
    return a.d < b.d;
}

int main() {

    while(true) {
        cin >> N;

        if(N == 0) break;

        int ret = 0;
        for(int i = 0; i < N; i++) set[i] = i;
        edge_vec.clear();

        for(int i = 1; i < N; i++) {
            char s;
            char v;
            int d;

            cin >> s >> K;

            for(int j = 0; j < K; j++) {
                cin >> v >> d;

                edge_vec.push_back(edge(v - 'A', s- 'A', d));
            }
        }

        sort(edge_vec.begin(), edge_vec.end(), cmp);

        for(auto e : edge_vec) {
            int a = e.a;
            int b = e.b;
            int d = e.d;

            if(!is_Union(a, b)) {
                Union(a, b);
                ret += d;
            }
        }

        ans.push_back(ret);
    }

    for(auto x:ans) {
        cout << x << "\n";
    }

    return 0;
}
