/*
  
  divide and conquer + recursion

*/

#include <iostream>

using namespace std;

int N;
char plane[2188][2188];

void solve(int r, int c, int n) {
    if(n == 1) {
        plane[r][c] = '*';
        return;
    }

    int dx = n/3;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) continue;
            solve(r + i*dx, c + j*dx, dx);
        }
    }   
    
}

int main() {

    cin >> N;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            plane[r][c] = ' ';
        }
    }

    solve(1, 1, N);

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cout << plane[r][c];
        }
        cout << "\n";
    }

    return 0;
}
