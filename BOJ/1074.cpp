/*
  
  silver 1
  
  divide and conquer + backtracking

*/

#include <iostream>
#include <cmath>

using namespace std;

int N;
int ans_cnt = 0;
int r, c;
int dr[4] = {0, 0, 1, 1};
int dc[4] = {0, 1, 0, 1};

void solve(int sr, int sc, int n) {
    if(n == 0) return;

    int dn = pow(2, n - 1);

    if(r < sr + dn && c < sc + dn) solve(sr, sc, n - 1);
    else if(r < sr + dn && c >= sc + dn) {
        ans_cnt += dn*dn;
        solve(sr, sc + dn, n - 1);
    }
    else if(r >= sr + dn && c < sc + dn) {
        ans_cnt += 2*dn*dn;
        solve(sr + dn, sc, n -1);
    }
    else {
        ans_cnt += 3*dn*dn;
        solve(sr + dn, sc + dn, n - 1);
    }

    /*
    solve(sr, sc, n - 1);
    solve(sr, sc + dn, n - 1);
    solve(sr + dn, sc, n - 1);
    solve(sr + dn, sc + dn, n - 1);
    */
}

int main() {

    cin >> N >> r >> c;

    solve(0, 0, N);

    cout << ans_cnt << "\n";

    return 0;
}
