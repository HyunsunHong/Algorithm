#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int sp;
    int ep = -30001;    
    
    sort(routes.begin(), routes.end());
    
    for(auto r : routes) {
        if(ep < r[0]) {
            answer++;
            sp = r[0];
            ep = r[1];
        }
        else {
            sp = r[0];
            if(r[1] <= ep) ep = r[1];
        }
    }
    
    
    return answer;
}
