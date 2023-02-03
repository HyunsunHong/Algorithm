#include <string>
#include <vector>

#define PLUS 0
#define MINUS 1

using namespace std;

vector<int> num_vec;
int answer = 0;
int Target;

void go(int idx, int cal) {
    if(idx == num_vec.size()) {
        if(cal == Target) answer++;
        
        return;
    }
    
    go(idx + 1, cal + num_vec[idx]);
    go(idx + 1, cal - num_vec[idx]);
    
}

int solution(vector<int> numbers, int target) {
    
    num_vec = numbers;
    Target = target;
    
    go(0, 0);
    
    return answer;
}
