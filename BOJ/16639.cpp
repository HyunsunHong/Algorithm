/*
  
  gold 1
  
  dp(top-down, memoization) 

*/

#include <iostream>
#include <cstring>

#define MAX 0
#define MIN 1
#define LLONG_MAX 9223372036854775807
#define LLONG_MIN -9223372036854775808 

using namespace std;

int N;
string input;
long long cache[20][20][2]; // max : 0, min : 1;

long long solve(int l, int r, int mode) {
    if(cache[r][l][mode] != LLONG_MAX) return cache[r][l][mode];

    long long & ret = cache[r][l][mode];

    if(r == l) return ret = input[l - 1] - '0';

    if(mode == MAX) ret = LLONG_MIN;

    for(int i = l + 1; i < r; i += 2) {
        char op = input[i - 1];

        if(op == '+') {
            if(mode == MAX) ret = max(ret, solve(l, i - 1, MAX) + solve(i + 1, r, MAX));
            else if(mode == MIN) ret = min(ret, solve(l, i - 1, MIN) + solve(i + 1, r, MIN));
        } 
        else if(op == '-') {
            if(mode == MAX) ret = max(ret, solve(l, i - 1, MAX) - solve(i + 1, r, MIN));
            else if(mode == MIN) ret = min(ret, solve(l, i - 1, MIN) - solve(i + 1, r, MAX));
        }
        else if(op == '*') {
            long long max_ret = LLONG_MIN;
            long long min_ret = LLONG_MAX;

            for(int j = 0; j < 2; j++) {
                for(int k = 0; k < 2; k++) {
                    max_ret = max(max_ret, solve(l, i - 1, j)*solve(i + 1, r, k));
                    min_ret = min(min_ret, solve(l, i - 1, j)*solve(i + 1, r, k));
                }
            }

            if(mode == MAX) ret = max(ret, max_ret);
            else if(mode == MIN) ret = min(ret, min_ret);
        }
    }

    return cache[r][l][mode] = ret;
}


int main() {

    cin >> N >> input;

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            for(int k = 0; k < 2; k++) {
                cache[i][j][k] = LLONG_MAX;
            }
        }
    }

    cout << solve(1, N, MAX);

    return 0;
}
