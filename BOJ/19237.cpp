/*
  
  gold 2
  
  implementation + simulation

*/

#include <iostream>

using namespace std;

int N, M, k;
int smell_shark[21][21];
int smell_time[21][21];
int curr_shark[21][21];
int curr_shark_dir[401];
int dir_priority[401][5][5]; // [shark][curr_dir][dir]
int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, -1, 1};
int ans = 0;
int cnt = 0;

bool possible(int r, int c) {
    if(r < 1 || r > N) return false;
    if(c < 1 || c > N) return false;
    return true;
}

bool is_end() {
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            if(curr_shark[r][c] > 1) return false; 
        }
    }
    return true;
}

void determine_next_shark_dir(int * next_shark_dir, int r, int c) {
    int curr_shark_num = curr_shark[r][c];
    int curr_dir = curr_shark_dir[curr_shark_num];

    for(int i = 1; i <= 4; i++) {
        int next_dir = dir_priority[curr_shark_num][curr_dir][i];
        int next_r = r + dr[next_dir];
        int next_c = c + dc[next_dir];

        if(possible(next_r, next_c) && smell_shark[next_r][next_c] == 0) {
            next_shark_dir[curr_shark_num] = next_dir;
            return;
        } 
    }

    for(int i = 1; i <= 4; i++) {
        int next_dir = dir_priority[curr_shark_num][curr_dir][i];
        int next_r = r + dr[next_dir];
        int next_c = c + dc[next_dir];

        if(possible(next_r, next_c) && smell_shark[next_r][next_c] == curr_shark_num) {
            next_shark_dir[curr_shark_num] = next_dir;
            return;
        } 
    }
}

void smell_reduction() {
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            if(smell_time[r][c] == 1) {
                smell_time[r][c]--;
                smell_shark[r][c] = 0;
            }
            else if(smell_time[r][c] > 1) smell_time[r][c]--; 
        }
    }
}

void move_shark(int * next_shark_dir) {
    int next_shark[21][21];

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            next_shark[r][c] = 0;
        } 
    }

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            if(curr_shark[r][c] != 0) {
                int shark_num = curr_shark[r][c];
                int next_r = r + dr[next_shark_dir[shark_num]];
                int next_c = c + dc[next_shark_dir[shark_num]];
                if(next_shark[next_r][next_c] == 0 || next_shark[next_r][next_c] > shark_num) {
                    next_shark[next_r][next_c] = shark_num;
                }
            }
        }
    }

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            curr_shark[r][c] = next_shark[r][c];

            if(curr_shark[r][c] != 0) {
                smell_shark[r][c] = curr_shark[r][c];
                smell_time[r][c] = k;
            }
        }
    }

    for(int i = 1; i <= M; i++) curr_shark_dir[i] = next_shark_dir[i];
}

void print_debug() {
    cout << "\n\n";
    
    cout << "curr shark\n";
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cout << curr_shark[r][c] << " ";
        }
        cout << "\n";
    }
    /*
    cout << "\ncurr smell_shark\n";
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cout << smell_shark[r][c] << " ";
        }
        cout << "\n";
    } */
    
    cout << "\ncurr smell_time\n";
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cout << smell_time[r][c] << " ";
        }
        cout << "\n";
    }
    
    cout << "\ncurr shark dir\n";
    for(int i = 1; i <= M; i++) cout << curr_shark_dir[i] << " ";
    cout << "\n";
}

void solve() {
    while(!is_end() && ans <= 1000) {
        ans++;

        int next_shark_dir[401] = {0, };

        //print_debug();

        for(int r = 1; r <= N; r++) {
            for(int c = 1; c <= N; c++) {
                if(curr_shark[r][c] != 0) {
                    determine_next_shark_dir(next_shark_dir, r, c);
                }
            }
        }

        smell_reduction();
        move_shark(next_shark_dir);
    }
}

int main() {

    cin >> N >> M >> k;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> curr_shark[r][c];
            smell_shark[r][c] = curr_shark[r][c];
            if(curr_shark[r][c] != 0) smell_time[r][c] = k;
        }
    }
    
    for(int i = 1; i <= M; i++) cin >> curr_shark_dir[i];

    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= 4; j++) {
            for(int k = 1; k <= 4; k++) {
                cin >> dir_priority[i][j][k];
            }
        }
    }

    solve();

    if(ans > 1000) ans = -1;
    cout << ans << "\n";

    return 0;
}
