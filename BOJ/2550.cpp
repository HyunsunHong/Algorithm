/*

    gold 3

    LIS (nlgn)

*/

#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 10001;
int arr[10001];
int LIS[10001];
int log[10001];
int ans = 0;
vector<int> ans_vec;
map<int, int> switch_idx; // <s, idx>
map<int, int> idx_switch;
int N;

void backtrace(int idx, int num) {
    if(idx == 0) return;

    if(log[idx] == num) {
        ans_vec.push_back(idx_switch[idx]);
        backtrace(idx - 1, num - 1);
    }
    else backtrace(idx - 1, num);
}

int main() {

    cin >> N;

    memset(LIS, INF, sizeof(LIS));

    for(int i = 1; i <= N; i++) {
        int input;
        cin >> input;
        switch_idx[input] = i;
        idx_switch[i] = input;
    } 
    for(int i = 1; i <= N; i++) {
        int input;
        cin >> input;

        arr[switch_idx[input]] = i;
    }

    for(int i = 1; i <= N; i++) {
        auto pos = lower_bound(LIS + 1, LIS + 1 + N, arr[i]);
        int idx = distance(LIS, pos);
        *pos = arr[i];
        log[i] = idx;
        
        if(pos == LIS + ans + 1) {
            ans++;
        }
    }  

    backtrace(N, ans);       

    sort(ans_vec.begin(), ans_vec.end());

    cout << ans << "\n";
    for(auto x : ans_vec) cout << x << " ";
   

    return 0;
}
