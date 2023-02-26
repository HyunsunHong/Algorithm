/*
    silver 4
    
    exhaustive search
  
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n;
int k;
int arr[11];
bool used[11];
vector<int> v;
set<string> s;

void go(int cnt) {
    if(cnt == k) {
        string str;
        for(auto i : v) {
            str.append(to_string(arr[i]));
        }
        s.insert(str);
    }

    for(int i = 1; i <= n; i++) {
        if(used[i]) continue;
        used[i] = true;
        v.push_back(i);
        go(cnt + 1);
        v.pop_back();
        used[i] = false;
    }    
}


int main() {

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    go(0);

    cout << s.size();

    return 0;
}
