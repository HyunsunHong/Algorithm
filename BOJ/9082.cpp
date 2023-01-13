#include <iostream>
// Not solved

#include <queue>

using namespace std;

int T, N;
string first_row;
string second_row;
vector<int> ans;
priority_queue<pair<int, int> > pq;

int main() {
    cin >> T;

    while(T--) {
        cin >> N >> first_row >> second_row;

        for(int i = 0; i < N; i++) {
            pq.push(make_pair(first_row[i] - '0', i));
        }

        while(!pq.empty()) {
            int idx = pq.top().second;
            int mine = pq.top().first;
            pq.pop();

            int mine_cnt = 0;

            if(idx - 1 >= 0 && second_row[idx - 1] == '*') mine_cnt++;
            if(idx + 1 < N && second_row[idx + 1] == '*') mine_cnt++;
            if(second_row[idx] == '*') mine_cnt++;

            if(mine_cnt == mine) {
                if(second_row[idx] == '#') second_row[idx] = '.';
                continue;
            }


        }
    }

    return 0;
}