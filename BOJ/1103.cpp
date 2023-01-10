/*
    gold 2

    dp(top-down) + dfs + backtracking 

*/

#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

const int INF = 987654321;
int N, M;
int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, 1, -1, 0};
int ans = 0;

vector<string> board;
int cache[50][50][4];

bool possible(int r, int c) {
    if(r < 0 || r > N - 1) return false;
    if(c < 0 || c > M - 1) return false;

    return true;
}

int solve(int r, int c, int dir) {

    if(cache[r][c][dir] != -1) {
        if(cache[r][c][dir] == 0) {
            return cache[r][c][dir] = INF;
        }
        return cache[r][c][dir];
    }

    cache[r][c][dir] = 0;
    int ret = 0;

    int next_r = r + dr[dir] * (board[r][c] - '0');
    int next_c = c + dc[dir] * (board[r][c] - '0');

    if(possible(next_r, next_c) && board[next_r][next_c] != 'H') {
        for(int i = 0; i < 4; i++) {
            ret = max(ret, solve(next_r, next_c, i));
        }
    }

    return cache[r][c][dir] = ++ret;
}

int main() {

    cin >> N >> M;

    memset(cache, -1, sizeof(cache));

    for(int i = 0; i < N; i++) {
        string input;

        cin >> input;
        board.push_back(input);
    }

    for(int i = 0; i < 4; i++) {
        ans = max(ans, solve(0, 0, i));
    }

    if(ans >= INF) ans = -1;

    cout << ans << "\n";

    return 0;
}