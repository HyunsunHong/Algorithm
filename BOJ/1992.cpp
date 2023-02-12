/*
  silver 1
  
  divide and conquer

*/

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> v;

void solve(int sr, int sc, int n) {
    int one_cnt = 0;
    int zero_cnt = 0;

    for(int r = sr; r < sr+ n; r++) {
        for(int c = sc; c < sc + n; c++) {
            if(v[r][c] == '0') zero_cnt++;
            else one_cnt++;
        }
    }

    if(one_cnt == 0 || zero_cnt == 0) {
        cout << v[sr][sc];
    }
    else {
        cout << "(";
                solve(sr, sc, n/2);
                solve(sr, sc + n/2, n/2);
                solve(sr + n/2, sc,  n/2);
                solve(sr + n/2, sc + n/2, n/2);
                cout << ")";
    }
}

int main() {

    cin >> N;

    for(int i = 0; i < N; i++) {
        string inp;

        cin >> inp;

        v.push_back(inp);
    }

    solve(0, 0, N);

    return 0;
}
