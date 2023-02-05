/*

    gold 2 

    prefix sum + dynamic programming

*/

#include <iostream>
#include <cstring>

#define MAX 100002

using namespace std;

int N;
long long cache[MAX][4];
long long sum[MAX];
long long val;
long long ans = 0;

long long solve(int idx, int cnt) {
    if(idx > N) return 0;

    if(cache[idx][cnt] != -1) return cache[idx][cnt];

    if(cnt == 3) {
        if(sum[N] - sum[idx - 1] == val) return cache[idx][cnt] = 1;
        else return cache[idx][cnt] = 0;
    }

    long long & ret = cache[idx][cnt];
    ret = 0;
    for(int i = idx; i <= N; i++) {
        if(sum[i] - sum[idx - 1] == val) {
            ret += solve(i + 1, cnt + 1);
        }
    }
    
    return ret;
}

int main() {

    cin >> N;

    memset(cache, -1, sizeof(cache));

    for(int i = 1; i <= N; i++) {
        cin >> sum[i];

        sum[i] += sum[i - 1];
    }

    if(sum[N] == 0) {
        long long zero_cnt = 0;

        for(int i = 1; i < N; i++) {
            if(sum[i] == 0) zero_cnt++;
        }

        ans = zero_cnt*(zero_cnt - 1)*(zero_cnt - 2)/6;
    }
    else {
        if(sum[N] % 4 == 0) {
            val = sum[N] / 4;

            for(int i = 1; i <= N; i++) {
                if(sum[i] == val) ans += solve(i + 1, 1);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
