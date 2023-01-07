/*

gold 4

dp, top-down using cache

전형적인 지도맵에서의 top-down dp문제.

0. cache[r][c][milk]의 의미는 '(r, c)상에서 최근 마신 우유가 milk일때 마신 우유의 최대 값'

1. 우유를 마실때딸기우유가 아닌 경우 이전 우유를 무조건 마신 상태여야만 한다 (45번줄)

2. 해당 우유를 마실 수 있을 때와 마실 수 없을 때를 구별해서 비교해야한다. (42, 50, 51번 줄)

*/


#include <iostream>
#include <cstring>

using namespace std;

int N;
int cache[1001][1001][3]; // 0 ~ 2(recently drunk)
int map[1001][1001];
int ans = 0;

int pre_milk(int milk) {
    if(milk == 0) return 2;
    
    return milk - 1;
}

int solve(int r, int c, int milk) {
    if(r < 1 || r > N) return 0;
    if(c < 1 || c > N) return 0;

    if(cache[r][c][milk] != -1) return cache[r][c][milk];

    int ret = 0;

    if(map[r][c] == milk) {
        ret = max(solve(r - 1, c, pre_milk(milk)), solve(r, c - 1, pre_milk(milk)));

        if(milk == 0 || ret != 0) {
            ret++;
        }
    }

    ret = max(ret, solve(r - 1, c, milk));
    ret = max(ret, solve(r, c - 1, milk));

    return cache[r][c][milk] = ret;
}

int main() {

    cin >> N;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> map[r][c];
        }
    }

    memset(cache, -1, sizeof(cache));

    ans = max(ans, solve(N, N, 0));
    ans = max(ans, solve(N, N, 1));
    ans = max(ans, solve(N, N, 2));

    cout << ans << "\n";

    return 0;
}