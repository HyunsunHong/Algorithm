/*

silver 2

backtracking

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<int> nums;
bool is_num[10001] = {false, };

void go(vector<int> v) {
    if(v.size() == M) {
        for(auto x : v) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }

    for(auto x : nums) {
        v.push_back(x);
        go(v);
        v.pop_back();
    }
}

int main() {

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;

        if(is_num[input]) continue;
        else {
            is_num[input] = true;
            nums.push_back(input);
        }
    }

    sort(nums.begin(), nums.end());

    vector<int> v;

    go(v);

    return 0;
}