/*

    stack + greedy

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    string input;
    vector<int> ans;

    while(cin >> input) {
        if(input[0] == '-') break;

        stack<char> s;
        int ret = 0;

        for(auto c : input) {
            if(s.empty()) {
                s.push(c);
                continue;
            }

            if(s.top() == '{' && c == '}') s.pop();
            else s.push(c);
        }

        while(!s.empty()) {
            char first_top = s.top();
            s.pop();
            char second_top = s.top();
            s.pop();

             if(second_top == '}' && first_top == '{') ret += 2;
             else ret += 1;
        }

        ans.push_back(ret);
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << i + 1 << ". " << ans[i] << "\n";
    }

    return 0;
}