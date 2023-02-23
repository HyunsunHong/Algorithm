/*
  
  silver 1
  
  backtracking

*/

#include <iostream>
#include <string>

using namespace std;

int k;
char arr[10];
bool used[10];
string ret;
string ans_max_str;
string ans_min_str;
bool is_first = true;

void go(int cnt, int pre_number) {

    if(cnt > k) {
        if(is_first) {
            is_first = false;
            ans_min_str = ret;
        }
        else {
            ans_max_str = ret;
        }
        return;
    } 

    if(arr[cnt] == '>') {
        for(int i = 0; i < pre_number; i++) {
            if(!used[i]) {
                used[i] = true;
                ret.push_back('0' + i);
                go(cnt + 1, i);
                used[i] = false;
                ret.pop_back();
            }
        }
    }
    else {
        for(int i = pre_number + 1; i < 10; i++) {
            if(!used[i]) {
                used[i] = true;
                ret.push_back('0' + i);
                go(cnt + 1, i);
                used[i] = false;
                ret.pop_back();
            }
        }
    }
}

int main() {
    cin >> k;

    for(int i = 1; i <= k; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < 10; i++) {
        ret.push_back('0' + i);
        used[i] = true;
        go(1, i);
        used[i] = false;
        ret.pop_back();
    }

    cout << ans_max_str << "\n" << ans_min_str << "\n"; 

    return 0;
}
