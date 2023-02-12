/*

  divide and conquer

*/

#include <iostream>

using namespace std;

int N;
int map[129][129];
int ans_zero = 0;
int ans_one = 0;

void solve(int sr, int sc, int n) {
    int one_cnt = 0;
    int zero_cnt = 0;

    for(int r = sr; r < sr + n; r++) {
        for(int c = sc; c < sc + n; c++) {
            if(map[r][c] == 1) one_cnt++;
            else zero_cnt++;
        }
    }

    if(one_cnt != 0 && zero_cnt != 0) {
        solve(sr, sc, n/2);
        solve(sr, sc + n/2, n/2);
        solve(sr + n/2, sc, n/2);
        solve(sr + n/2, sc + n/2, n/2);
    }
    else {
        if(one_cnt != 0) ans_one++;
        else ans_zero++;
    }
}

int main() {

    cin >> N;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> map[r][c];
        }
    }    

    solve(1, 1, N);

    cout << ans_zero << "\n" << ans_one;

    return 0;
}
