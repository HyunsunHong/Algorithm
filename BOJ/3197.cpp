/*
  
  platinum 5
  
  union-find + bfs

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
vector<string> map;
vector<pair<int, int> > swans;
char lake[1501][1501];
int set[2250001];
bool visited[1501][1501];
queue<pair<int, int> > water_q;
queue<pair<int, int> > next_q;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
long long ans = -1;

bool possible(int r, int c) {
    if(r < 1 || r > R) return false;
    if(c < 1 || c > C) return false;

    return true;
}

int parent(int x) {
    if(set[x] == x) return x;

    return set[x] = parent(set[x]);
}

void Union(int a, int b) {
    a = parent(a);
    b = parent(b);
    
    if(a < b) set[b] = a;
    else set[a] = b;
}

bool is_Union(int a, int b) {
    return parent(a) == parent(b);
}

int node_number(int r, int c) {
    return (r-1)*C + c;
}

bool is_swan_union() {
    return parent(node_number(swans[0].first, swans[0].second)) == parent(node_number(swans[1].first, swans[1].second));
}

void print_debug() {
    cout << "\n";
    cout << ans << "\n";
    for(int r = 1; r <= R; r++) {
        for(int c = 1; c <= C; c++) {
            cout << lake[r][c];
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {

    cin >> R >> C;

    for(int r = 1; r <= R; r++) {
        string input;
        cin >> input;

        for(int c = 0; c < C; c++) {
            lake[r][c + 1] = input[c];
            set[node_number(r, c + 1)] = node_number(r, c + 1);

            if(input[c] != 'X') {
                water_q.push(make_pair(r ,c + 1));
            }
            if(input[c] == 'L') swans.push_back(make_pair(r, c + 1));
        }
    } 

    do {
        ans++;

        while(!water_q.empty()) {
            int r = water_q.front().first;
            int c = water_q.front().second;
            water_q.pop();

            for(int i = 0; i < 4; i++) {
                int next_r = r + dr[i];
                int next_c = c + dc[i];

                if(possible(next_r, next_c)) {
                    if(lake[next_r][next_c] == 'X' && !visited[next_r][next_c]) {
                        next_q.push(make_pair(next_r, next_c));
                        visited[next_r][next_c] = true;
                    }
                    else if(lake[next_r][next_c] != 'X'){
                        Union(node_number(r, c), node_number(next_r, next_c));
                    }
                }
            }
        }

        //cout << "before\n";
        //print_debug();

        while(!next_q.empty()) {
            water_q.push(next_q.front());
            int r = next_q.front().first;
            int c = next_q.front().second;
            next_q.pop();

            lake[r][c] = '.';
        }

        //cout << "after\n";
        //print_debug();

    } while(!is_swan_union());

    cout << ans << "\n";

    return 0;
}
