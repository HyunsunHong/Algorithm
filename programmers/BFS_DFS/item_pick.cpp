#include <string>
#include <queue>

struct node {
    int x;
    int y;
    int d;
    
    node(int X, int Y, int D) : x(X), y(Y), d(D) {}
};

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int map[101][101];
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    for(auto r : rectangle) {
        for(int x = r[0]*2; x <= r[2]*2; x++) {
            map[x][r[1]*2] = 1;
            map[x][r[3]*2] = 1;
        }
        for(int y = r[1]*2; y <= r[3]*2; y++) {
            map[r[0]*2][y] = 1;
            map[r[2]*2][y] = 1;
        }
    }     
    
    for(auto r : rectangle) {
        for(int x = r[0]*2 + 1; x <= r[2]*2 - 1; x++) {
            for(int y = r[1]*2 + 1; y <= r[3]*2 - 1; y++) {
                map[x][y] = 0;
            }
        }
    }
    
    queue<node> q;
    bool visited[101][101];
    
    q.push(node(characterX*2, characterY*2, 0));
    visited[characterX*2][characterY*2] = true;
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
            if(!visited[next_x][next_y]) {
                if(next_x == itemX*2 && next_y == itemY*2) {
                    return (d + 1)/2;
                }
                else if(map[next_x][next_y] == 1){
                    visited[next_x][next_y] = true;
                    q.push(node(next_x, next_y, d + 1));
                }
            }
        }
    }
    
    
    return answer;
}
