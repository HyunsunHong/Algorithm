/*
  
  gold 1
  
  implementaion + simulation

*/

#include <iostream>
#include <vector>

#define W 1
#define NW 2
#define N 3
#define NE 4
#define E 5
#define SE 6
#define S 7
#define SW 8

struct fish {
    int r;
    int c;
    int d;

    fish(int R, int C, int D) : r(R), c(C), d(D) {}
};

using namespace std;

vector<vector<vector<int> > > curr_board_fish; // value is direction
int curr_board_smell[5][5]; // value is time
vector<vector<vector<int> > > next_board_fish;
int next_board_smell[5][5];

int m, s;
int sr, sc;
int dr[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dc[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int d_pri[4] = {N, W, S, E};
vector<int> shark_move;
int ate_fish;
int ans = 0;
bool ate[5][5];

bool possible(int r, int c) {
    if(r < 1 || r > 4) return false;
    if(c < 1 || c > 4) return false;
    return true;
}

int next_d_45(int d) {
    if(d - 1 == 0) return SW;
    return d - 1;
}

fish next_position(int r, int c, int d) {
    for(int i = 1; i <= 8; i++) {
        int next_r = r + dr[d];
        int next_c = c + dc[d];
        int next_d = d;

        d = next_d_45(d);

        if(possible(next_r, next_c) && curr_board_smell[next_r][next_c] == 0 && !(next_r == sr && next_c == sc)) {
            return fish(next_r, next_c, next_d);
        }
    }

    return fish(r, c, d);
}

void shark_go(vector<int> move_log, int fish_cnt, int r, int c) {
    if(move_log.size() == 3) {
        if(fish_cnt > ate_fish || shark_move.empty()) {
            ate_fish = fish_cnt;
            shark_move = move_log;
        }
        return;
    }

    for(int i = 0; i < 4; i++) {
        int next_r = r + dr[d_pri[i]];
        int next_c = c + dc[d_pri[i]];
        bool here_ate = false;
    
        if(possible(next_r, next_c)) {
            move_log.push_back(d_pri[i]);
            if(!ate[next_r][next_c]) {
                fish_cnt += next_board_fish[next_r][next_c].size();
                ate[next_r][next_c] = true;
                here_ate = true;
            }

            shark_go(move_log, fish_cnt, next_r, next_c);
            
            move_log.pop_back();

            if(here_ate) {
                fish_cnt -= next_board_fish[next_r][next_c].size();
                ate[next_r][next_c] = false;
            }
        } 
    }
}

void debug_print() {
/*
    cout << "\n\ncurr fish:\n";
    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            cout << curr_board_fish[r][c].size() << " "; 
        }
        cout << "\n";
    }
    cout << "\n";*/
    cout << "\n\n" << sr << " " << sc << "\n";
    cout << "next fish:\n";
    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            cout << next_board_fish[r][c].size() << " "; 
        }
        cout << "\n";
    }
    cout << "\n";
}

void debug_smell() {
    /*
    cout << "\n\ncurr smell: \n";
    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            cout << curr_board_smell[r][c].size() << " ";
        }
        cout << "\n";
    }*/
    
    cout << "\n\nnext smell: \n";
    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            cout << next_board_smell[r][c] << " ";
        }
        cout << "\n";
    }
}

void practice() {
    next_board_fish.clear();

    for(int i = 0; i < 5; i++) {
        vector<vector<int> > v(5);
        next_board_fish.push_back(v);
    }

    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            next_board_smell[r][c] = 0;
        }
    }   

    // 2
    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            if(curr_board_fish[r][c].empty()) continue;

            for(auto d : curr_board_fish[r][c]) {
                fish next_fish = next_position(r, c, d);
                next_board_fish[next_fish.r][next_fish.c].push_back(next_fish.d);
            }
        }
    }

    // 3
    shark_move.clear();
    ate_fish = 0;
    vector<int> move_log;
    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            ate[r][c] = false;
        }
    }
    shark_go(move_log, 0, sr, sc);

    for(auto d : shark_move) {
        sr += dr[d];
        sc += dc[d];

        if(next_board_fish[sr][sc].empty()) continue;

        next_board_smell[sr][sc] = (2);
        
        next_board_fish[sr][sc].clear();
    }

    //debug_print();
    
    // 4 - here to debug
    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            if(curr_board_smell[r][c] == 0) continue;;
    
            next_board_smell[r][c] = max(next_board_smell[r][c], curr_board_smell[r][c] - 1);
        }
    }
    
    // 5
    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            if(curr_board_fish[r][c].empty()) continue;

            for(auto d:curr_board_fish[r][c]) {
                next_board_fish[r][c].push_back(d);
            }
        }
    }

    // next
    curr_board_fish = next_board_fish;
    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            curr_board_smell[r][c] = next_board_smell[r][c];
        }
    }

    //debug_smell();
    //debug_print();
}

int main() {

    for(int i = 0; i < 5; i++) {
        vector<vector<int> > v(5);

        curr_board_fish.push_back(v);
    }   

    cin >> m >> s;

    for(int i = 0; i < m; i++) {
        int fx, fy, d;

        cin >> fx >> fy >> d;

        curr_board_fish[fx][fy].push_back(d);
    }

    cin >> sr >> sc;

    while(s--) {
        practice();
    }

    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            if(curr_board_fish.empty()) continue;

            ans += curr_board_fish[r][c].size();
        }
    }

    cout << ans << "\n";

    return 0;
}
