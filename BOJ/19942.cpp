/*

    gold 5

    bruteforce + backtracking

*/


#include <iostream>
#include <vector>

using namespace std;

struct food {
    int mp;
    int mf;
    int ms;
    int mv;
    int cost;

    food(int p, int f, int s, int v, int c) : mp(p), mf(f), ms(s), mv(v), cost(c) {}
};

const int INF = 987654321;
int N;
vector<food> food_vec;
int ans_cost = INF;
vector<int> ans_vec;
int mp, mf, ms, mv;
bool is_used[15] = {false, };

bool is_sufficient(int mp_cnt, int mf_cnt, int ms_cnt, int mv_cnt) {
    if(mp_cnt < mp) return false;
    if(mf_cnt < mf) return false;
    if(ms_cnt < ms) return false;
    if(mv_cnt < mv) return false;

    return true;
}

void go(int idx, int mp_cnt, int mf_cnt, int ms_cnt, int mv_cnt, int ret_cost) {
    if(idx >= N) return;

    if(is_sufficient(mp_cnt + food_vec[idx].mp, mf_cnt + food_vec[idx].mf, ms_cnt + food_vec[idx].ms, mv_cnt + food_vec[idx].mv)) {
        if(ans_cost > ret_cost + food_vec[idx].cost) {
            ans_cost = ret_cost + food_vec[idx].cost;
            ans_vec.clear();
            for(int i = 0; i < N; i++) {
                if(is_used[i]) {
                    ans_vec.push_back(i + 1);
                }
            }
            ans_vec.push_back(idx + 1);
        }
    }
    else if(ret_cost + food_vec[idx].cost < ans_cost) {
        is_used[idx] = true;
        go(idx + 1, mp_cnt + food_vec[idx].mp, mf_cnt + food_vec[idx].mf, ms_cnt + food_vec[idx].ms, mv_cnt + food_vec[idx].mv, ret_cost + food_vec[idx].cost);
        is_used[idx] = false;
    }

    go(idx + 1, mp_cnt, mf_cnt, ms_cnt, mv_cnt, ret_cost);
}

int main() {    

    cin >> N;

    cin >> mp >> mf >> ms >> mv;

    for(int i = 0; i < N; i++) {
        int p, f, s, v, cost;

        cin >> p >> f >> s >> v >> cost;

        food_vec.push_back(food(p, f, s, v, cost));
    }

    go(0, 0, 0, 0, 0, 0);

    if(ans_cost == INF) cout << -1;
    else {
        cout << ans_cost << "\n";
        for(auto x : ans_vec) cout << x << " ";
    }

    return 0;
}
