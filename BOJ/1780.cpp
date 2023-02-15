/*
  silver 2
  
  divide and conquer

*/

#include <iostream>

using namespace std;

int N;
int ans[3] = {0, };
int map[2187][2187];

void solve(int sr, int sc, int n) {
    for(int r = sr; r < sr + n; r++) {
        for(int c = sc; c < sc + n; c++) {
            if(map[sr][sc] != map[r][c]) {
                int dn = n/3;

                solve(sr, sc, dn);
                solve(sr, sc + dn, dn);
                solve(sr, sc + dn*2, dn);

                solve(sr + dn, sc, dn);
                solve(sr + dn, sc + dn, dn);
                solve(sr + dn, sc + dn*2, dn);

                solve(sr + 2*dn, sc, dn);
                solve(sr + 2*dn, sc + dn, dn);
                solve(sr + 2*dn, sc + 2*dn, dn);

                return;
            }
        }
    }
    
    //cout << sr << " " << sc << " " << map[sr][sc] << "\n";

    if(map[sr][sc] == -1) ans[0]++;
    else if(map[sr][sc] == 0) ans[1]++;
    else ans[2]++;
}

int main() {

    cin >> N;

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            cin >> map[r][c];
        }
    }

    solve(0, 0, N);

    for(int i = 0; i < 3; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
