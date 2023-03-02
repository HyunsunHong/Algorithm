#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
            
    int lo = 0;
    int hi = people.size() - 1;
    
    sort(people.begin(), people.end());
    
    while(lo <= hi) {
        answer++;
        
        if(lo == hi) break;
        
        if(people[lo] + people[hi] <= limit) {
            lo++;
            hi--;
        }
        else {
            hi--;
        }
    }
    
    return answer;
}
