/* 

gold 4

dp, top-down
*/

#include <iostream>
#include <cstring>

using namespace std;

long long cache[2001][2001];
int N;
long long A[2001];
long long B[2001];

long long solve(int a, int b) {
    if(a == 0 || b == 0) return 0;

    if(cache[a][b] != -1) return cache[a][b];
    
    cache[a][b] = max(solve(a - 1, b), solve(a - 1, b - 1));

    if(A[a] > B[b]) cache[a][b] = max(cache[a][b], B[b] + solve(a, b - 1));

    return cache[a][b];
}

int main() { 

    memset(cache, -1, sizeof(cache));

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> A[N - i];
    }

    for(int i = 0; i < N; i++) {
        cin >> B[N - i];
    }

    cout << solve(N, N) << "\n";

    return 0;
}