/*

    gold 3

    mst with kruskal

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct edge{
    int a;
    int b;
    int d;

    edge(int A = 0, int B = 0, int D = 0) : a(A), b(B), d(D) {}
};

int N, C;
int ans = 0;
vector<pair<int, int> > fields;
vector<edge> edges;
int set[2001];

bool cmp(edge a, edge b) {
    return a.d < b.d;
}

int Euclidean_distance(pair<int, int> f1, pair<int, int> f2) {

    return pow(f1.first - f2.first, 2) + pow(f1.second - f2.second, 2);  
}

int getParent(int x) {
    if(set[x] == x) return x;

    return set[x] = getParent(set[x]);
}

void Union(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if(a < b) set[b] = a;
    else set[a] = b;
}

bool isUnion(int a, int b) {
    return getParent(a) == getParent(b);
}

int main() {

    cin >> N >> C;

    for(int i = 0; i < N; i++) {
        int x, y;

        cin >> x >> y;

        fields.push_back(make_pair(x, y));
    } 

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int d = Euclidean_distance(fields[i], fields[j]);

            if(d >= C) {
                edges.push_back(edge(i + 1, j + 1, d));
            }
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    for(int i = 1; i <= N; i++) set[i] = i;
    for(auto e : edges) {
        int a = e.a;
        int b = e.b;
        int d = e.d;

        if(!isUnion(a, b)) {
            ans += d;
            Union(a, b);
        }
    }

    for(int i = 1; i < N; i++) {
        if(!isUnion(i, i + 1)) {
            ans = -1;
        }
    }

    cout << ans << "\n";

    return 0;
}