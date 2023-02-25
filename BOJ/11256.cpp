/*

  silver 5
  
  greedy

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int J, N;
vector<int> ans;

int main() {

    cin >> T;

    while(T--) {
        cin >> J >> N;

        vector<int> box;
        int R, C;
        int ret = 0;

        while(N--) {
            cin >> R >> C;

            box.push_back(R*C);
        }

        sort(box.begin(), box.end(), greater<int> ());
        
        for(auto b : box) {
            ret++;
            J -= b;
            if(J <= 0) break;
        }

        ans.push_back(ret);
    }

    for(auto a : ans) {
        cout << a << "\n";
    }

    return 0;
}
