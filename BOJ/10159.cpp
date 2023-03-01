/*
  
  gold 4
  
  floyd-warshall

*/

#include <iostream>
#include <cstring>

using namespace std;

int N, M;
bool is_bigger[101][101];

void floyd_warshall() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(is_bigger[i][k] && is_bigger[k][j]) {
                    is_bigger[i][j] = true;
                }
            }
        }
    }
}

int main() {

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            is_bigger[i][j] = false; 
        }
    }

    for(int i = 0; i < M; i++) {
        int a, b;

        cin >> a >> b;

        is_bigger[a][b] = true; 
    }

    floyd_warshall();

    for(int i = 1; i <= N; i++) {
        int unknown_cnt = 0;

        for(int j = 1; j <= N; j++) {
            if(i == j) continue;

            if(!is_bigger[i][j] && !is_bigger[j][i]) {
                unknown_cnt++;
            }
        }

        cout << unknown_cnt << "\n";
    }

    return 0;
}
