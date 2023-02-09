/*

    gold 2

    divide and conquer + tree traversal

*/

#include <iostream>
#include <vector>

using namespace std;

int T;
int pre_order[1001];
int in_order[1001];
int N;
vector<int> ret;
vector<vector<int> > ans;

void post_print(int pre_lo, int pre_hi, int in_lo, int in_hi) {
    if(pre_hi < pre_lo) return;

    int root = pre_order[pre_lo];
    
    for(int i = in_lo; i <= in_hi; i++) {
        if(in_order[i] == root) {
            int r_cnt = in_hi - i;
            post_print(pre_lo + 1, pre_hi - r_cnt, in_lo, i - 1);
            post_print(pre_hi - r_cnt + 1, pre_hi, i + 1, in_hi);
            break;
        } 
    }

    ret.push_back(root);
}

int main() {

    cin >> T;

    while(T--) {
        cin >> N;

        ret.clear();

        for(int i = 1; i <= N; i++) {
            cin >> pre_order[i];
        }
        for(int i = 1; i <= N; i++) {
            cin >> in_order[i];
        }

        post_print(1, N, 1, N);

        ans.push_back(ret);
    }

    for(auto v : ans) {
        for(auto x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
