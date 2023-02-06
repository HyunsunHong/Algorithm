/*
  
  gold 4
  
  union-find

*/

#include <iostream>

using namespace std;

int T;
int N, M;
int set[1001];

int parent(int x) {
    if(set[x] == x) return x;
    return set[x] = parent(set[x]);
}

void Union(int a, int b) {
    a = parent(a);
    b = parent(b);

    if(a < b) set[b]= a;
    else set[a] = b;
}

bool is_Union(int a, int b) {
    return parent(a) == parent(b);
}


int main() {

    cin >> T;

    while(T--) {
        bool is_tree = true;

        cin >> N >> M;

        for(int i = 1; i <= N; i++) set[i] = i;

        for(int i = 0; i < M; i++) {
            int u, v;

            cin >> u >> v;

            if(is_Union(u, v)) is_tree = false;
            else Union(u ,v);
        }

        for(int i = 1; i < N; i++) {
            if(!is_Union(i, i + 1)) is_tree = false;
        }

        if(is_tree) cout << "tree\n";
        else cout << "graph\n";
    }



    return 0;
}
