/*
    silver 5

    simple implementation + queue

*/

#include <iostream>
#include <queue>

using namespace std;

int N;
int ans[1001];
int time_cnt = 0;

int main() {

    queue<pair<int, int> > q;

    cin >> N;

    for(int i = 1; i <= N; i++) {
        int input;

        cin >> input;

        q.push(make_pair(input, i));
    }

    while(!q.empty()) {
        time_cnt++;

        int need = q.front().first;
        int person = q.front().second;

        need--;

        if(need == 0) ans[person] = time_cnt;
        else q.push(make_pair(need, person));

        q.pop();
    }

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}