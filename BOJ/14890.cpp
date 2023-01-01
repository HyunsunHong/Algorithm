// gold3

// implementaion

#include <iostream>

using namespace std;

int N, L;
int Map[101][101];
int ans = 0;

bool search(int r, int c, bool is_row_search) {
    int slope_possible_idx = 1;
    int curr_idx = 1;

    if(is_row_search) {
        while(curr_idx < N) {
            if(Map[r][curr_idx] == Map[r][curr_idx + 1]) curr_idx++;
            else if(Map[r][curr_idx] - Map[r][curr_idx + 1] == 1) {
                for(int i = 1; i <= L; i++) {
                    if(curr_idx + i > N || (Map[r][curr_idx] - Map[r][curr_idx + i] != 1)) return false;
                }
                curr_idx += L;
                slope_possible_idx = curr_idx + 1;
            }
            else if(Map[r][curr_idx] - Map[r][curr_idx + 1] == -1) {
                if(curr_idx - slope_possible_idx + 1 >= L) {
                    curr_idx++;
                    slope_possible_idx = curr_idx;
                }
                else return false;
            }
            else {
                return false;
            }
        }
        return true;
    }
    
    while(curr_idx < N) {
            if(Map[curr_idx][c] == Map[curr_idx + 1][c]) curr_idx++;
            else if(Map[curr_idx][c] - Map[curr_idx + 1][c] == 1) {
                for(int i = 1; i <= L; i++) {
                    if(curr_idx + i > N || (Map[curr_idx][c] - Map[curr_idx + i][c] != 1)) return false;
                }
                curr_idx += L;
                slope_possible_idx = curr_idx + 1;
            }
            else if(Map[curr_idx][c] - Map[curr_idx + 1][c] == -1) {
                if(curr_idx - slope_possible_idx + 1 >= L) {
                    curr_idx++;
                    slope_possible_idx = curr_idx;
                }
                else return false;
            }
            else {
                return false;
            }
        }
        return true;
}

int main() {

    cin >> N >> L;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> Map[r][c];
        }
    }

    for(int i = 1; i <= N; i++) {
       if(search(i, 0, true)) ans++;
       if(search(0, i, false)) ans++;
    }

    cout << ans << "\n";

    return 0;
}