/*
  
  gold 5
  
  bfs

*/

#include <iostream>
#include <queue>

#define PLANE 0
#define LADDER 1
#define SNAKE 2

using namespace std;

struct node {
    int x;
    int cnt;

    node(int X, int CNT) : x(X), cnt(CNT) {}
};

int N, M;
int board[101];
int destinaltion[101];
bool visiited[101];
int d[6] = {1, 2, 3, 4, 5, 6};

int bfs() {
    queue<node> q;

    visiited[1] = true;
    q.push(node(1, 0));

    while(!q.empty()) {
        int x = q.front().x;
        int cnt = q.front().cnt;

        q.pop();

        for(int i = 0; i < 6; i++) {
            int next_x = x + d[i];
            //cout << next_x << "\n";

            if(next_x > 100 || visiited[next_x]) continue;

            if(next_x == 100) return cnt + 1;

            if(board[next_x] == LADDER || board[next_x] == SNAKE) { 
                visiited[next_x] = true;
                visiited[destinaltion[next_x]] = true;
                q.push(node(destinaltion[next_x], cnt + 1));
            }
            else {
                visiited[next_x] = true;
                q.push(node(next_x, cnt + 1));
            }  
        }
    }

    return -1;
}

int main() {

    cin >> N >> M;

    while(N--) {
        int x, y;

        cin >> x >> y;

        board[x] = LADDER;
        destinaltion[x] = y;
    }

    while(M--) {
        int u, v;

        cin >> u >> v;

        board[u] = SNAKE;
        destinaltion[u] = v;
    }

    cout << bfs() << "\n";

    return 0;
}
