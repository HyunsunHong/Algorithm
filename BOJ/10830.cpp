/*
  
  divide and conquer

*/

#include <iostream>
#include <vector>

using namespace std;

long long N, B;
long long ans[5][5];
long long A[5][5];

void multiply(long long A[5][5], long long B[5][5]) {
    long long temp[5][5];

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            temp[r][c] = 0;

            for(int k = 0; k < N; k++) {
                temp[r][c] += A[r][k] * B[k][c];
            }

            temp[r][c] %= 1000;
        }
    }

    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 5; c++) {
            A[r][c] = temp[r][c];
        }
    }
}

int main() {

    cin >> N >> B;

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            cin >> A[r][c];
        }
        ans[r][r] = 1;
    }

    while(B != 0) {
        if(B % 2 == 1) {
            multiply(ans, A);
        }
        multiply(A, A);
        B /= 2;
    }

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            cout << ans[r][c] << " ";
        }
        cout << "\n";
    }
 
    return 0;
}
