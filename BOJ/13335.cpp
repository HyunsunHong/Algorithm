#include <iostream>
/*

    silver 1

    simulatin + queue + implementation

    simple

*/

#include <queue>

using namespace std;

int n, w, L;
int bridge[1001] = {0, };
queue<int> q;
int ans = 0;

int total() {
    int sum = 0;

    for(int i = 1; i <= w; i++) {
        sum += bridge[i];
    }

    return sum;
}

int main() {

    cin >> n >> w >> L;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;

        q.push(input);
    }

    while(!q.empty() || total() != 0) {
        ans++;
        for(int i = 1; i <= w; i++) {
            bridge[i - 1] = bridge[i];
        }
        bridge[w] = 0;

        if(!q.empty()) {
            if(L >= total() + q.front()) {
                bridge[w] = q.front();
                q.pop();
            }
        }
    }

    cout << ans;

    return 0;
}