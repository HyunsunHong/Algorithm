#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool used[10000] = {false, };
vector<string> ans;

bool dfs(string curr, vector<vector<string> > tickets) {
    if(ans.size() == tickets.size() + 1) {
        return true;
    }
    
    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == curr && !used[i]) {
            ans.push_back(tickets[i][1]);
            used[i] = true;
            if(dfs(tickets[i][1], tickets)) return true;
                
            ans.pop_back();
            used[i] = false;
        }          
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end());
    
    ans.push_back("ICN");
    dfs("ICN", tickets);
    
    answer = ans;
    
    return answer;
}
