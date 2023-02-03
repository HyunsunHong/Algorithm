/*

    gold 5
    
    greedy + bfs

*/

#include <iostream>
#include <queue>
#include <cstring>

#define MAX 61

using namespace std;

int T, N;
int ans[MAX][5];
bool visited[MAX] = {false, };
int dt[5] = {60, 10, -10, 1, -1};

bool possible(int x) {
    if(x < 0 || x > MAX - 1) return false;
    return true;
}

void bfs() {
    queue<int> q;
    visited[0] = true;

    q.push(0);

    while(!q.empty()) {
        int curr = q.front();

        q.pop();

        for(int i = 4; i >= 0; i--) {
            int next = curr + dt[i];

            if(possible(next) && !visited[next]) {
                visited[next] = true;
                q.push(next);

                for(int j = 0; j < 5; j++) {
                    ans[next][j] = ans[curr][j];
                    if(i == j) ans[next][j]++;
                }
            }
        }
    }
}

int main() {

    cin >> T;

    memset(ans, 0, sizeof(ans));

    bfs();

    while(T--) {
        cin >> N;

        int ADDH = N / 60;
        int rest = N % 60;

        cout << ans[rest][0] + ADDH << " " << ans[rest][1] << " " << ans[rest][2] << " " << ans[rest][3] << " " << ans[rest][4] << "\n";
    }

    return 0;
}