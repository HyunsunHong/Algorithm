#include <iostream>
#include <cstring>

using namespace std;

int N;
int cache[1001][1001][4]; // 
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

    if(milk <= 3) {
        if(map[r][c] == milk) {
            ret =  max(solve(r - 1, c, pre_milk(milk)), solve(r, c - 1, pre_milk(milk)));
            
            if(milk == 0) {
                ret++;
            }
            else {
                if(ret != 0) {
                    ret++;
                }
            }

            return cache[r][c][milk] = ret;
        }
        else {
            return cache[r][c][milk] = 0;
        }
    }
    else {
        for(int i = 0; i <= 3; i++) {
            ret = max(ret, solve(r - 1, c, i));
            ret = max(ret, solve(r, c - 1, i));
        }

        return cache[r][c][milk] = ret;
    }
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
    ans = max(ans, solve(N, N, 3));

    cout << ans << "\n";

    return 0;
}