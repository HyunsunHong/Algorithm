#include <vector>
#include <queue>

struct node {
    int r;
    int c;
    int d;
    
    node(int R, int C, int D) : r(R), c(C), d(D) {}
};

using namespace std;

bool possible(int r, int c, int n, int m) {
    if(r < 0 || r >= n) return false;
    if(c < 0 || c >= m) return false;
    return true;
}

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    bool visited[100][100];
    int n = maps.size();
    int m = maps[0].size();
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            visited[i][j] = false;
        }
    }
    
    queue<node> q;
    q.push(node(0, 0, 1));
    visited[0][0] = true;

    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int d = q.front().d;
        
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];
            
            if(possible(next_r, next_c, n, m) && maps[next_r][next_c] == 1 && !visited[next_r][next_c]) {
                visited[next_r][next_c] = true;
                if(next_r == n - 1 && next_c == m - 1) return d + 1;
                q.push(node(next_r, next_c, d + 1));
            }
        }
    }
    
    return answer;
}
