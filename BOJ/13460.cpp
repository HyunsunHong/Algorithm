/*

gold 1

simulation + brute force + "backtracking + dfs" 

*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int ans = 11;
bool visited[10][10][10][10][10];

// when this function is called, it is assumed that both blue and red exist in board.
// need to go next (both blue and red exist) -> return true
bool up(vector<string> &board, int cnt) {
    bool blue_hole = false;
    bool red_hole = false;

    for(int r = 1; r < N - 1; r++) {
        for(int c = 1; c < M - 1; c++) {
            if((board[r][c] == 'B' || board[r][c] == 'R') && (board[r - 1][c] == '.' || board[r - 1][c] == 'O')){
                int next_r = r - 1;
                while(board[next_r][c] == '.') {
                    next_r--;
                }

                if(board[next_r][c] == 'O') {
                    if(board[r][c] == 'B') blue_hole = true;
                    else if(board[r][c] == 'R') red_hole = true;
                }
                else {
                    board[next_r + 1][c] = board[r][c];
                }
                board[r][c] = '.';
            }
        }
    }

    if(blue_hole || red_hole) {
        if(!blue_hole && red_hole) ans = min(ans, cnt);
        return false;
    }

    return true;
}

bool down(vector<string> &board, int cnt) {
    bool blue_hole = false;
    bool red_hole = false;

    for(int r = N - 2; r >= 1; r--) {
        for(int c = 1; c < M - 1; c++) {
            if((board[r][c] == 'B' || board[r][c] == 'R') && (board[r + 1][c] == '.' || board[r + 1][c] == 'O')){
                int next_r = r + 1;
                while(board[next_r][c] == '.') {
                    next_r++;
                }

                if(board[next_r][c] == 'O') {
                    if(board[r][c] == 'B') blue_hole = true;
                    else if(board[r][c] == 'R') red_hole = true;
                }
                else {
                    board[next_r - 1][c] = board[r][c];
                }
                board[r][c] = '.';
            }
        }
    }

    if(blue_hole || red_hole) {
        if(!blue_hole && red_hole) ans = min(ans, cnt);
        return false;
    }

    return true;
}

bool right(vector<string> &board, int cnt) {
    bool blue_hole = false;
    bool red_hole = false;

    for(int c = M - 2; c > 0; c--) {
        for(int r = 1; r < N - 1; r++) {
            if((board[r][c] == 'B' || board[r][c] == 'R') && (board[r][c + 1] == '.' || board[r][c + 1] == 'O')){
                int next_c = c + 1;
                while(board[r][next_c] == '.') {
                    next_c++;
                }

                if(board[r][next_c] == 'O') {
                    if(board[r][c] == 'B') blue_hole = true;
                    else if(board[r][c] == 'R') red_hole = true;
                }
                else {
                    board[r][next_c - 1] = board[r][c];
                }
                board[r][c] = '.';
            }
        }
    }

    if(blue_hole || red_hole) {
        if(!blue_hole && red_hole) ans = min(ans, cnt);
        return false;
    }

    return true;
}

bool left(vector<string> &board, int cnt) {
    bool blue_hole = false;
    bool red_hole = false;

    for(int c = 1; c < M - 1; c++) {
        for(int r = 1; r < N - 1; r++) {
            if((board[r][c] == 'B' || board[r][c] == 'R') && (board[r][c - 1] == '.' || board[r][c - 1] == 'O')){
                int next_c = c - 1;
                while(board[r][next_c] == '.') {
                    next_c--;
                }

                if(board[r][next_c] == 'O') {
                    if(board[r][c] == 'B') blue_hole = true;
                    else if(board[r][c] == 'R') red_hole = true;
                }
                else {
                    board[r][next_c + 1] = board[r][c];
                }
                board[r][c] = '.';
            }
        }
    }

    if(blue_hole || red_hole) {
        if(!blue_hole && red_hole) ans = min(ans, cnt);
        return false;
    }

    return true;
}

void go(vector<string> board, int cnt) {
    if(cnt == 10) return;  

    int red_r, red_c, blue_r, blue_c;

    for(int r = 1; r < N - 1; r++) {
        for(int c = 1; c < M - 1; c++) {
            if(board[r][c] == 'R') {
                red_r = r;
                red_c = c;
            }
            else if(board[r][c] == 'B') {
                blue_r = r;
                blue_c = c;
            }
        }
    }

    if(visited[red_r][red_c][blue_r][blue_c][cnt]) return;
    else visited[red_r][red_c][blue_r][blue_c][cnt] = true;

    vector<string> up_board = board;
    vector<string> down_board = board;
    vector<string> left_board = board;
    vector<string> right_board = board;

    if(up(up_board, cnt + 1)) {
        go(up_board, cnt + 1);
    }
    if(down(down_board, cnt + 1)) {
        go(down_board, cnt + 1);
    }
    if(left(left_board, cnt + 1)) {
        go(left_board, cnt + 1);
    }
    if(right(right_board, cnt + 1)) {
        go(right_board, cnt + 1);
    }

}

void debug_print(vector<string> board) {
    vector<string> up_board = board;
    vector<string> down_board = board;
    vector<string> left_board = board;
    vector<string> right_board = board;
   
    cout << "up\n";
    up(up_board, 1);

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            cout << up_board[r][c];
        }
        cout << "\n";
    }

    cout << "down\n";
    down(down_board, 1);

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            cout << down_board[r][c];
        }
        cout << "\n";
    }

    cout << "right\n";
    right(right_board, 1);

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            cout << right_board[r][c];
        }
        cout << "\n";
    }

    cout << "left\n";
    left(left_board, 1);

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            cout << left_board[r][c];
        }
        cout << "\n";
    }
    
}

int main() {

    vector<string> board;

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;

        board.push_back(input);
    }

    memset(visited, false, sizeof(visited));

    //debug_print(board);

    go(board, 0);

    if(ans == 11) ans = -1;

    cout << ans << "\n";

    return 0;
}