/*

    floyd_warshall

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 100;
int dist[51][51];
int N, u, v;
vector<int> ans_vec;
int ans_score = INF;

void floyd_warshall() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {

    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dist[i][j] = INF;
        }
    }
    for(int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    while(true) {
        cin >> u >> v;

        if(u == -1 && v == -1) break;

        dist[u][v] = 1;
        dist[v][u] = 1;
    }

    floyd_warshall();

    for(int i = 1; i <= N; i++) {
        int ret = 0;

        for(int j = 1; j <= N; j++) ret = max(ret, dist[i][j]);
        
        if(ans_score > ret) {
            ans_score = ret;
            ans_vec.clear();
            ans_vec.push_back(i);
        }
        else if(ans_score == ret) {
            ans_vec.push_back(i);
        }
    }

    cout << ans_score << " " << ans_vec.size() << "\n";
    for(auto x : ans_vec) {
        cout << x << " ";
    }

    return 0;
}
