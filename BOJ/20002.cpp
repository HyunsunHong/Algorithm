/*
  
  gold 5
  
  accum sum + brute force

*/

#include <iostream>

using namespace std; 

int N;
int sum[301][301];
int ans = -90000000;

void test(int sr, int sc, int k) {
    int ret = 0;

    for(int r = sr; r <= sr + k - 1; r++) {
        ret += sum[r][sc + k - 1] - sum[r][sc - 1];
    }

    ans = max(ans, ret);
}

int main() {

    cin >> N;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> sum[r][c];
            sum[r][c] += sum[r][c - 1];
        }
     }

    for(int k = 1; k <= N; k++) {
        for(int r = 1; r + k - 1 <= N; r++) {
            for(int c = 1; c + k - 1 <= N; c++) {
                test(r, c, k);
            }
        }  
    }

    cout << ans << "\n";

    return 0;
}
