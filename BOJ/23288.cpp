/*
  
  implementation + silumation + dfs
  
  gold 3
  
*/

#include <iostream>
#include <stack>

#define EAST 0
#define WEST 1
#define NORTH 2
#define SOUTH 3

using namespace std;

int N, M, K;
int board[21][21];
int curr_r = 1;
int curr_c = 1;
int curr_d = EAST;
int Front = 5;
int Rear = 2;
int Up = 1;
int Down = 6;
int Right = 3;
int Left = 4;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
int score[21][21];
int ans = 0;

int pre_r;
int pre_c;
int pre_d;

bool possible(int r, int c) {
    if(r < 1 || r > N) return false;
    if(c < 1 || c > M) return false;
    return true;
}

void roll_east() {
    int temp_up = Up;
    int temp_down = Down;
    int temp_left = Left;
    int temp_right = Right;

    Down = temp_right;
    Right = temp_up;
    Up = temp_left;
    Left = temp_down;
}

void roll_west() {
    int temp_up = Up;
    int temp_down = Down;
    int temp_left = Left;
    int temp_right = Right;

    Down = temp_left;
    Right = temp_down;
    Left = temp_up;
    Up = temp_right;
}

void roll_south() {
    int temp_up = Up;
    int temp_down = Down;
    int temp_front = Front;
    int temp_rear = Rear;

    Down = temp_front;
    Front = temp_up;
    Up = temp_rear;
    Rear = temp_down;
}

void roll_north() {
    int temp_up = Up;
    int temp_down = Down;
    int temp_front = Front;
    int temp_rear = Rear;

    Down = temp_rear;
    Front = temp_down;
    Up = temp_front;
    Rear = temp_up;
}

void get_score(int r, int c) {
    bool visited[21][21];

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= M; c++) {
            visited[r][c] = false;
        } 
    }

    int cnt = 1;
    stack<pair<int, int> > s;
    
    s.push(make_pair(r, c));
    visited[r][c] = true;

    while(!s.empty()) {
        //cout << curr_r << " " << curr_c << "\n";

        int curr_r = s.top().first;
        int curr_c = s.top().second;
        s.pop();

        for(int i = 0; i < 4; i++) {
            int next_r = curr_r + dr[i];
            int next_c = curr_c + dc[i];

            //cout << next_r << " " << next_c << "\n";

            if(possible(next_r, next_c) && !visited[next_r][next_c] && board[next_r][next_c] == board[curr_r][curr_c]) {
                cnt++;
                visited[next_r][next_c] = true;
                s.push(make_pair(next_r, next_c));
            }
        }
    }

    score[r][c] = cnt*board[r][c];
}

void rotate_90(int &d, bool is_cw) {
    if(!is_cw) {
        if(d == EAST) d = NORTH;
        else if(d == NORTH) d = WEST;
        else if(d == WEST) d = SOUTH;
        else if(d == SOUTH) d = EAST;
    }
    else {
        if(d == EAST) d = SOUTH;
        else if(d == SOUTH) d = WEST;
        else if(d == WEST) d = NORTH;
        else d = EAST;
    }
}

void rotate_180(int &d) {
    if(d == EAST) d = WEST;
    else if(d == WEST) d = EAST;
    else if(d == NORTH) d = SOUTH;
    else d = NORTH;
}

void roll() {
    int next_r = curr_r + dr[curr_d];
    int next_c = curr_c + dc[curr_d];
    pre_d= curr_d;

    if(!possible(next_r, next_c)) rotate_180(curr_d);
    
    if(curr_d == WEST) roll_west();
    else if(curr_d == EAST) roll_east();
    else if(curr_d == NORTH) roll_north();
    else roll_south();

    pre_r = curr_r;
    pre_c = curr_c;
    curr_r += dr[curr_d];
    curr_c += dc[curr_d];
    ans += score[curr_r][curr_c];

    if(Down > board[curr_r][curr_c]) rotate_90(curr_d, true);
    else if(Down < board[curr_r][curr_c]) rotate_90(curr_d, false);
}

int main() {

    cin >> N >> M >> K;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= M; c++) {
            cin >> board[r][c];
        }
    }

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= M; c++) {
            get_score(r, c);
        }
    }

    while(K--) {
        roll();

        //cout << "pre_r, pre_c, pre_d: " << pre_r << " " << pre_c << " " << pre_d <<  " curr_r, curr_c, curr_d: " << curr_r << " " << curr_c << " " << curr_d << " " << " Down, board[curr_r][curr_c] "<< Down << " " << board[curr_r][curr_c]  <<"\n";
      
    }

    cout << ans << "\n";

    return 0;
}
