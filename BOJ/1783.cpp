/*
  
  silver 3
  
  greedy
  
*/

#include <iostream>

using namespace std;

int N, M;
int n = 1;
int m = 1;
int ans = 1;

int main() {

    cin >> N >> M;

    if(N == 1) cout << 1 << "\n";
    else if(N == 2) cout << min(4, (M + 1)/2) << "\n";
    else {
        if(M >= 7) cout << M - 2 << "\n";
        else cout << min(4, M) << "\n";
    }
    

    return 0;
}
