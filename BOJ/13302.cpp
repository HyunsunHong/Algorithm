/*


*/
#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;
int N, M;
int cache[101][101]; // cache[day][coupon]
bool is_day_off[101] = {false, };

int solve(int day, int coupon) {

    if(day > N) return 0;

    if(cache[day][coupon] != -1) return cache[day][coupon];

    int &ret = cache[day][coupon];
    ret = INF;

    if(is_day_off[day]) return ret = solve(day + 1, coupon);

    if(coupon >= 3) ret = min(ret, solve(day + 1, coupon - 3));
    ret = min(ret, 10000 + solve(day + 1, coupon));
    ret = min(ret, 25000 + solve(day + 3, coupon + 1));
    ret = min(ret, 37000 + solve(day + 5, coupon + 2));

    return cache[day][coupon] = ret;
}

int main() {

    memset(cache, -1, sizeof(cache));

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int day_off;

        cin >> day_off;

        is_day_off[day_off] = true;
    }

    cout << solve(1, 0) << "\n";

    return 0;
}