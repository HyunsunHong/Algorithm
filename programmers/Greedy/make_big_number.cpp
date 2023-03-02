#include <string>
#include <vector>
#include <cstring>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int lo = 0;
    int hi = 1;
    bool banned[1000000];
    
    memset(banned, false, sizeof(banned));
    
    while(k) {
        if(number[lo] < number[hi]) {
            banned[lo] = true;
            k--;
            
            while(lo >= 0 && banned[lo]) lo--;
            
            if(lo == -1) {
                lo = hi;
                hi++;        
            } 
        }
        else {
            if(hi == number.size() - 1) {
                k--;
                banned[hi] = true;
                hi = lo;
                
                while(lo >= 0 && banned[lo]) lo--;
            }
            else {
                lo = hi;
                hi++;
            }
        }
    }
    
    for(int i = 0; i < number.size(); i++) {
        if(!banned[i]) answer.push_back(number[i]);
    }
    
    return answer;
}
