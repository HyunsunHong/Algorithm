/*
  
  gold 4
  
  implementation + simulation

*/

#include <iostream>
#include <vector>

using namespace std;

int N;
bool Map[101][101];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};
int ans = 0;

void count_rect() {
    for(int r = 0; r < 100; r++) {
        for(int c = 0; c < 100; c++) {
            if(Map[r][c] && Map[r + 1][c] && Map[r][c + 1] && Map[r + 1][c + 1]) {
                ans++;
            }
        }
    }
}

void draw_curve(int r, int c, int d, int g) {
    vector<int> draw_vec;
    Map[r][c] = true;
    draw_vec.push_back(d);

    while(g--) {
        vector<int> temp_vec;

        for(int i = draw_vec.size() - 1; i >= 0; i--) {
            temp_vec.push_back((draw_vec[i] + 1) % 4);
        }
        for(auto c : temp_vec) {
            draw_vec.push_back(c);
        }
    }

    for(auto d : draw_vec) {
        r += dr[d];
        c += dc[d];
        Map[r][c] = true;
    }
}


int main() {

    cin >> N;

    for(int i = 0; i < N; i++) {
        int x, y, d, g;

        cin >> x >> y >> d >> g;

        draw_curve(y, x, d, g);
    }

    count_rect();

    cout << ans << "\n";

    return 0;
}
