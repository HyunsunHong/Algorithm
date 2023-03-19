/*
  silver 3
  
  bfs
  
*/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int A, K;
int cache[1000001];

void bfs() {
    queue<pair<int, int> > q;

    cache[A] = 0;
    q.push(make_pair(A, 0));

    while(!q.empty()) {
        int curr = q.front().first;
        int cnt = q.front().second;
        //cout << curr << "\n";
        q.pop();

        if(curr * 2 <= K && cache[curr * 2] == -1) {
            cache[curr * 2] = cnt + 1;
            q.push(make_pair(curr * 2, cnt + 1));

            if(curr * 2 == K) return;
        } 
        if(curr + 1 <= K && cache[curr + 1] == -1) {
            cache[curr + 1] = cnt + 1;
            q.push(make_pair(curr + 1, cnt + 1));

            if(curr + 1 == K) return;
        } 
    }
}
 
int main() {

    cin >> A >> K;

    memset(cache, -1, sizeof(cache));

    cache[A] = 0;

    bfs();

    cout << cache[K] << "\n";

    return 0;
}
