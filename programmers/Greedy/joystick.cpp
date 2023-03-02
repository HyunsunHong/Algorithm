#include <string>
#include <vector>

using namespace std;


int solution(string name) {
    int answer = 0;
    int min_move = name.size() - 1;
    int N = name.size();
    
    for(int i = 0; i < name.size(); i++) {
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
    }
    
    for(int i = 0; i < name.size(); i++) {      
        int end_idx = i + 1;
        
        while(end_idx < name.size() && name[end_idx] == 'A') {
            end_idx++;
        }
        
        min_move = min(min_move, min(i*2 + N - end_idx, 2*(N - end_idx) + i));
    }
    
    answer += min_move;
        
    return answer;
}
