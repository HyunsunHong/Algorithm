/*
  
  gold 4
  
  bitwise operation

*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int remember = 0;
int word[10000] = {0, };
vector<int> ans;

int main() {

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string inp;
        cin >> inp;
        for(auto c : inp) {
            word[i] = word[i] | (1 << c - 'a');
        }
    }

    for(int i = 0; i < 26; i++) {
        remember = remember | (1 << i);
    }

    while(M--) {
        int o;
        char x;
        cin >> o >> x;

        if(o == 1) {
            remember = remember & ~(1 << x - 'a');
        }
        else if(o == 2) {
            remember = remember | (1 << x - 'a');
        }
        
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if((remember & word[i]) == word[i]) cnt++; 
        } 

        ans.push_back(cnt);
    }

    for(auto x : ans) {
        cout << x << "\n";
    }

    return 0;
}
