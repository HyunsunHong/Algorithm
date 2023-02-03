#include <string>
#include <vector>

using namespace std;

vector<vector<int>> adj;
bool visited[200];

void dfs(int node) {
    visited[node] = true;
    
    for(int i = 0; i < adj[node].size(); i++) {
        int is_adj = adj[node][i];
        
        if(visited[i] == true || is_adj == 0) continue;
        
        dfs(i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    adj = computers;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            answer++;
            dfs(i);
        }
    }
    
    return answer;
}
