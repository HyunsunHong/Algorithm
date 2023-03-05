/*
  gold 5
  
  stack
  
*/

#include <iostream>
#include <stack>

using namespace std;

stack<pair<char, int> > s;
int N, K;
string str;

int main() {

    cin >> N >> K >> str;

    for(auto c : str) {
        if(s.empty() || s.top().first != c) {
            s.push(make_pair(c, 1));
        } 
        else {
            if(s.top().second == K - 1) {
                while(!s.empty() && s.top().first == c) {
                    s.pop();
                }
            }
            else {
                s.push(make_pair(c, s.top().second + 1));
            } 
        }
    }

    stack<char> ans;

    while(!s.empty()) {
        ans.push(s.top().first);
        s.pop();
    }

    while(!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }

    return 0;
}
