/*
  
  gold 3
  
  implementation + data structure + simulation

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int nutrition[11][11];
int curr_nuturient[11][11];
vector<vector<vector<int> > > curr_trees;
vector<vector<vector<int> > > dead_trees;
int dr[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};

bool possible(int r, int c) {
    if(r < 1 || r > N) return false;
    if(c < 1 || c > N) return false;
    return true;
}

void spring() {
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            if(curr_trees[r][c].empty()) continue;

            vector<int> next_trees;
            sort(curr_trees[r][c].begin(), curr_trees[r][c].end());
            for(auto age : curr_trees[r][c]) {
                if(age > curr_nuturient[r][c]) dead_trees[r][c].push_back(age);
                else {
                    next_trees.push_back(age + 1);
                    curr_nuturient[r][c] -= age;
                }
            }
            curr_trees[r][c] = next_trees;
        }
    }
}

void summer() {
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            if(dead_trees[r][c].empty()) continue;

            for(auto age : dead_trees[r][c]) curr_nuturient[r][c] += age/2;
            dead_trees[r][c].clear();
        }
    }
}

void fall() {
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            if(curr_trees[r][c].empty()) continue;

            for(auto age : curr_trees[r][c]) {
                if(age % 5 == 0) {
                    for(int i = 0; i < 8; i++) {
                        int next_r = r + dr[i];
                        int next_c = c + dc[i];

                        if(possible(next_r, next_c)) curr_trees[next_r][next_c].push_back(1);
                    }
                }
            }
        }
    }
}

void winter() {
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            curr_nuturient[r][c] += nutrition[r][c];
        }
    }
}

int count_trees() {
    int ret = 0;
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            if(curr_trees[r][c].empty()) continue;
            ret += curr_trees[r][c].size();
        }
    }

    return ret;
}

int main() {

    cin >> N >> M >> K;

    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= N; c++) {
            cin >> nutrition[r][c];
            curr_nuturient[r][c] = 5;
        }
    }

    for(int r = 0; r <= N; r++) {
        vector<vector<int> > temp_vec(N + 1);
        curr_trees.push_back(temp_vec);
        dead_trees.push_back(temp_vec);
    }

    while(M--) {
        int x, y, z;

        cin >> x >> y >> z;
        curr_trees[x][y].push_back(z);
    }

    while(K--) {
        spring();
        summer();
        fall();
        winter();
    }
    
    cout << count_trees() << "\n";

    return 0;
}
