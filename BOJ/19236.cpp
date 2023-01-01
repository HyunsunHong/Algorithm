// gold 2

// brute force + simulation
// passing values, not address using vectors

#include <iostream>
#include <vector>

using namespace std;

struct state {
    int r;
    int c;
    int d;

    state(int R = 0, int C = 0, int D = 0) : r(R), c(C), d(D) {}
};

int dr[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dc[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int ans = 0;

int nextDir(int d) {
    d++;

    if(d == 9) return 1;
    
    return d;
}

bool possible(int r, int c) {
    if(r < 0 || r > 3) return false;
    if(c < 0 || c > 3) return false;
    return true;
}

void go(vector<vector<int> > fish_map, vector<state> fish_states, int score_cnt) {

    // move fish
    for(int fish_num = 1; fish_num <= 16; fish_num++) {
        if(fish_states[fish_num].d == 0) {
            continue;
        }

        int r = fish_states[fish_num].r;
        int c = fish_states[fish_num].c;
        int d = fish_states[fish_num].d;

        for(int i = 0; i < 8; i++) {

            int next_r = r + dr[d];
            int next_c = c + dc[d];

            if(!possible(next_r, next_c) || fish_map[next_r][next_c] == -1) {
                d = nextDir(d);
                continue;
            }

            // empty
            if(fish_map[next_r][next_c] == 0) {
                swap(fish_map[r][c], fish_map[next_r][next_c]);
                fish_states[fish_num].r = next_r;
                fish_states[fish_num].c = next_c;
                fish_states[fish_num].d = d;
                break;
            }
            else { // exist fish
                int next_fish = fish_map[next_r][next_c];
                swap(fish_map[r][c], fish_map[next_r][next_c]);
                swap(fish_states[fish_num].r, fish_states[next_fish].r);
                swap(fish_states[fish_num].c, fish_states[next_fish].c);
                fish_states[fish_num].d = d;
                break;
            }

            d = nextDir(d);
        }
    }

    // move done
    // now time to eat (shark) and recursive brute force (next 'go' call)
    bool fish_found = false;
    int shark_r = fish_states[0].r;
    int shark_c = fish_states[0].c;
    int shark_d = fish_states[0].d;

    fish_map[shark_r][shark_c] = 0;
    
    int next_r = shark_r;
    int next_c = shark_c;

    for(int i = 0; i < 3; i++) {
        next_r += dr[shark_d];
        next_c += dc[shark_d];

        if(!possible(next_r, next_c)) {
            break;
        }

        if(fish_map[next_r][next_c] != 0) {
            fish_found = true;
            int ate_fish_num = fish_map[next_r][next_c];
            int ate_fish_d = fish_states[ate_fish_num].d;

            fish_states[0].d = ate_fish_d;
            fish_states[0].r = next_r;
            fish_states[0].c = next_c;
            score_cnt += ate_fish_num;
            fish_map[next_r][next_c] = -1;

            fish_states[ate_fish_num].d = 0;

            go(fish_map, fish_states, score_cnt);

            fish_states[0].d = shark_d;
            fish_states[0].r = shark_r;
            fish_states[0].c = shark_c;
            score_cnt -= ate_fish_num;
            fish_map[next_r][next_c] = ate_fish_num;

            fish_states[ate_fish_num].d = ate_fish_d;
        }
    }
    
    if(!fish_found) {
        ans = max(ans, score_cnt);
    }
}

int main() {
    vector<vector<int> > fish_map(4);  // val == 0 -> not exist
    vector<state> fish_states(17); // index == 0 -> shark, d == 0 -> not exist
    int score_cnt = 0;

    for(int r = 0; r < 4; r++) {
        for(int c = 0; c < 4; c++) {
            int a, b;

            cin >> a >> b;

            fish_map[r].push_back(a);

            fish_states[a] = state(r, c, b);
        }
    }

    score_cnt = fish_map[0][0];
    fish_states[0] = state(0, 0, fish_states[fish_map[0][0]].d);
    fish_states[fish_map[0][0]].d = 0;  // fish death
    fish_map[0][0] = -1; // shark starts at (0, 0)
    ans = score_cnt;

    go(fish_map, fish_states, score_cnt);

    cout << ans << "\n";

    return 0;
}
