// Gold 3

// Dikstra + time saving

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 2000000000;
int N, M;
int X, Y;
int max_weight[10001]; // in terms of X

vector<vector<pair<int, int> > > adj(10001);

void dijkstra() {
    priority_queue<pair<int, int> > q;

    max_weight[X] = INF;
    q.push(make_pair(INF, X));

    while(!q.empty()) {
        int currNode = q.top().second;
        int currWeight = q.top().first;

        q.pop();

        for(auto iter = adj[currNode].begin(); iter != adj[currNode].end(); iter++) {
            int nextNode = iter->first;
            int nextWeight = min(iter->second, currWeight);

            if(max_weight[nextNode] < nextWeight) {
                max_weight[nextNode] = nextWeight;
                q.push(make_pair(nextWeight, nextNode));
            }
        }

        if(currNode == Y) break;
    }

}

int main() {

    cin >> N >> M;

    memset(max_weight, -1, sizeof(max_weight));    

    for(int i = 0; i < M; i++) {
        int A, B, C;

        cin >> A >> B >> C;

        adj[A].push_back(make_pair(B, C));
        adj[B].push_back(make_pair(A, C));
    }

    cin >> X >> Y;

    dijkstra();

    cout << max_weight[Y] << "\n";

    return 0;
}