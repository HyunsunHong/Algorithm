/*

  gold 5
  
  divide and conquer

*/

#include <iostream>

using namespace std;

int N;

void solve(int n, int k, int len) {
    int new_len = len*2 + k + 3;
    if(n <= 3) {
        if(n == 1) cout << "m\n";
        else cout << "o\n";
        return;
    }
    else if(n > new_len) {
        solve(n, k + 1, new_len);
    }
    else {
        if(n == len + 1) {
            cout << "m\n";
            return;
        }
        else if(n <= len + k + 3) {
            cout << "o\n";
            return;
        }
        n -= len + k + 3;
        solve(n, 1, 3);
    }
}

int main() {    

    cin >> N;

    solve(N, 1, 3);

    return 0;
}
