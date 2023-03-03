#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > min_heap;
    
    for(auto s : scoville) {
        min_heap.push(s);
    }
    
    while(min_heap.top() < K) {
        if(min_heap.size() == 1) {
            answer = -1;
            break;
        }
        
        int s1 = min_heap.top();
        min_heap.pop();
        int s2 = min_heap.top();
        min_heap.pop();
        
        
        int new_s = s1 + s2 * 2; 
        min_heap.push(new_s);
        
        answer++;
    }
    
    return answer;
}
