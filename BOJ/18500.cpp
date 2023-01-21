/* 
    to modify:
    1. gravity : buttom_air, visited revise
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define LEFT 0
#define RIGHT 1

using namespace std;

int R, C, N;
vector<string> map;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool possible(int r, int c) {
    if(r < 0 || r > R - 1) return false;
    if(c < 0 || c > C - 1) return false;

    return true; 
}

void debug_print() {
    for(int r = 0; r < R; r++) {
        cout << map[r] << "\n";
    }

    cout << "\n";
}


void gravity_bfs(int r, int c, bool visited[][100]) {
    // extract buttoms first
    queue<pair<int, int> > q;
    vector<pair<int, int> > buttom_air_vec;
    vector<pair<int, int> > cluster_vec;
    bool buttom_reach = false;

    visited[r][c] = true;
    cluster_vec.push_back(make_pair(r, c));
    q.push(make_pair(r, c));

    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];

            if(possible(next_r, next_c) && !visited[next_r][next_c] && map[next_r][next_c] == 'x') {
                cluster_vec.push_back(make_pair(next_r, next_c));
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));

                if(next_r == R - 1) buttom_reach = true;
                else if(map[next_r + 1][next_c] == '.') buttom_air_vec.push_back(make_pair(next_r, next_c));
            }
        }
    }  

    if(!buttom_reach) {
        int dr_drop = R;

        for(auto p : buttom_air_vec) {
            r = p.first + 1;
            c = p.second;

            while(possible(r, c) && map[r][c] == '.') r++;
            r--;

            dr_drop = min(dr_drop, r - p.first);
        }

        for(auto p : cluster_vec) {
            r = p.first;
            c = p.second;

            map[r][c] = '.';
        }
        for(auto p : cluster_vec) {
            r = p.first;
            c = p.second;

            map[r + dr_drop][c] = 'x';
        }
    }
}

void bomb(int r, int c) {
    // bomb!
    cout << "bomb! : " << r << " " <<  c << "\n";
    map[r][c] = 'B';
    debug_print();
    map[r][c] = '.';

    bool visited[100][100];
    memset(visited, false, sizeof(visited));
    visited[r][c] = true;
    
    for(int i = 0; i < 4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];

        if(possible(next_r, next_c) && !visited[next_r][next_c] && map[next_r][next_c] == 'x') {
            gravity_bfs(next_r, next_c, visited);
            cout << "after : " << next_r << " " << next_c << "\n";
            char temp = map[next_r][next_c];
            char temp1 = map[r][c];
            map[r][c] = 'B';
            map[next_r][next_c] = '!';
            debug_print();
            map[next_r][next_c] = temp;
            map[r][c] = temp1;
        } //6 6 4 3 1
    }
    
}

void shot(int h, int dir) {
    int shot_r = R - h;
    int shot_c;
    int dc;

    if(dir == LEFT) {
        dc = 1;
        shot_c = 0;
    }
    else if(dir == RIGHT) {
        dc = -1;
        shot_c = C - 1;
    }

    do {    
        if(map[shot_r][shot_c] == 'x') {
            bomb(shot_r, shot_c);
            break;
        }
        shot_c += dc;
    } while(possible(shot_r, shot_c));
}
 
int main() {

    cin >> R >> C;

    for(int r = 0; r < R; r++) {
        string input;

        cin >> input;

        map.push_back(input);
    }

    cin >> N;

    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;

        shot(input, i%2);
    }

    for(int r = 0; r < R; r++) {
        cout << map[r] << "\n";
    }


    return 0;
}