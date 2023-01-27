/*
  
  platinum 4
  
  mst with kruskal

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

int N, P;
int cost[10001];
int min_cost = 1001;
int set[100001];
int ans = 0;
vector<edge> edge_vec;

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

    cin >> N >> P;

    for(int i = 1; i <= N; i++) {
        cin >> cost[i];
        min_cost = min(min_cost, cost[i]);
        set[i] = i;
    }

    for(int i = 0; i < P; i++) {
        int a, b, d;

        cin >> a >> b >> d;

        edge_vec.push_back(edge(a, b, d*2 + cost[a] + cost[b]));
    }

    sort(edge_vec.begin(), edge_vec.end(), cmp);

    for(auto e : edge_vec) {
        int a = e.a;
        int b = e.b;
        int d = e.d;

        if(!is_Union(a, b)) {
            Union(a, b);
            ans += d;
        }
    }

    ans += min_cost;

    cout << ans;

    return 0;
}
