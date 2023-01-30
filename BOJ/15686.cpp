/*

  gold 5
  
  implementation + simulation + bruteforce + backtracking

*/

#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool chicken_closed[13] = {false, };
vector<pair<int, int> > chickens;
vector<pair<int, int> > homes;
int ans;

int ret_cal() {
    int ret = 0;

    for(auto h : homes) {
        int h_r = h.first;
        int h_c = h.second;
        int c_d = 987654321;

        for(int i = 0; i < chickens.size(); i++) {
            if(chicken_closed[i]) continue;

            int c_r = chickens[i].first;
            int c_c = chickens[i].second;

            c_d = min(c_d, abs(c_r - h_r) + abs(c_c - h_c));
        }  

        ret += c_d;
    }

    return ret;
}

void go(int to_close_idx, int closed_cnt) {
    if(closed_cnt == chickens.size() - M) {
        ans = min(ans, ret_cal());
        return;
    }
    if(to_close_idx == chickens.size()) return;

    if(ret_cal() > ans) return;

    chicken_closed[to_close_idx] = true;
    go(to_close_idx + 1, closed_cnt + 1);
    chicken_closed[to_close_idx] = false;

    go(to_close_idx + 1, closed_cnt);
}



int main() {

    cin >> N >> M;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            int input;
            cin >> input;

            if(input == 1) homes.push_back(make_pair(r, c));
            else if(input == 2) chickens.push_back(make_pair(r, c));
        }
    }

    ans = 987654321;

    go(0, 0);

    cout << ans;

    return 0;
}
