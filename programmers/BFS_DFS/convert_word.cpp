#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {\
    
    int answer = 0;
    bool visited[50] = {false, };
    queue<pair<string, int> > q;
                                                                 
    q.push(make_pair(begin, 0));
                                                                 
    while(!q.empty()) {
        string word = q.front().first;
        int ret = q.front().second;
        q.pop();
        
        for(int j = 0; j < words.size(); j++) {
            string w = words[j];
            if(word.size() != w.size()) continue;
            
            int diff_cnt = 0;
            
            for(int i = 0; i < word.size(); i++) {
                if(word[i] != w[i]) diff_cnt++;
            }
            
            if(diff_cnt == 1) {
                if(w.compare(target) == 0) {
                    return ret + 1;
                }
                else if(!visited[j]) {
                    visited[j] = true;
                    q.push(make_pair(w, ret + 1));
                }
            }
        }
    
    }
                                                                 
    return answer;
}
