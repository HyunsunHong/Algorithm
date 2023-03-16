/*
  
  gold 1
  
  implementation + simulation

*/

#include <iostream>
#include <vector>

using namespace std;

struct Shark {
    int s;
    int d;
    int z;

    Shark(int S, int D, int Z) : s(S), d(D), z(Z) {}    
};

int R, C, M;
int curr_c = 0;
int ans = 0;
int dr[6] = {0, -1, 1, 0, 0, 0};
int dc[6] = {0, 0, 0, 1, -1, 0};
vector<vector<vector<Shark> > > Map;

void catch_shark() {
    for(int r = 1; r <= R; r++) {
        if(!Map[r][curr_c].empty()) {
            Map[r][curr_c].clear();
            ans += Map[r][curr_c][0].z;
            return;
        }
    }
}

bool possible(int r, int c) {
    if(r < 1 || r > R) return false;
    if(c < 1 || c > C) return false;
    return true;
}

int invert_d(int d) {
    if(d == 1) return 2;
    if(d == 2) return 1;
    if(d == 3) return 4;
    return 3;
}

void move(int &r, int &c, int s, int &d) {
    if(d == 1 || d == 2) s %= (R - 1)*2;
    else s %= (C - 1)*2;
    while(s--) {
        int next_r = r + dr[d];
        int next_c = c + dc[d];

        if(!possible(next_r, next_c)) {
            d = invert_d(d);
            next_r = r + dr[d];
            next_c = c + dc[d];
        }
        
        r = next_r;
        c = next_c;
    }
}

void move_shark() {
    vector<vector<vector<Shark> > > next_Map;
    for(int r = 0; r <= R; r++) {
        vector<vector<Shark> > v(C + 1);
        next_Map.push_back(v);
    }

    for(int r = 1; r <= R; r++) {
        for(int c = 1; c <= C; c++) {
            if(!Map[r][c].empty()) {
                int next_r = r;
                int next_c = c;
                Shark s = Map[r][c][0];
                move(next_r, next_c, s.s, s.d);
                
                if((!next_Map[next_r][next_c].empty() && next_Map[next_r][next_c][0].z < s.z) || next_Map[next_r][next_c].empty()) {
                    next_Map[next_r][next_c].clear();
                    next_Map[next_r][next_c].push_back(s);
                }
            }
        }
    }

    Map = next_Map;
}

int main() {

    cin >> R >> C >> M;
    
    for(int r = 0; r <= R; r++) {
        vector<vector<Shark> > v(C + 1);
        Map.push_back(v);
    }

    for(int i = 0; i < M; i++) {
        int r, c, s, d, z;

        cin >> r >> c >> s >> d >> z;

        Map[r][c].push_back(Shark(s, d, z));
    }

    while(curr_c < C) {
        curr_c++;
        catch_shark();
        move_shark();
    } 

    cout << ans << "\n";

    return 0;
}
