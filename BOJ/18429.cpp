/*
  silver 3
  
  brute force + backtracking

*/

#include <iostream>

using namespace std;

int N, K;
bool used[9];
int kit[9];
int day[9];
int muscle = 500;
int ans = 0;

void go(int cnt) {
    if(cnt == N) {
        ans++;
        return;
    } 

    for(int i = 1; i <= N; i++) {
        if(!used[i]) {
            if(muscle - K + kit[i] >= 500) {
                muscle -= K;
                muscle += kit[i];
                used[i] = true;
                go(cnt + 1);
                muscle += K;
                muscle -= kit[i];
                used[i] = false;
            }
        }
    }
} 

int main() {

    cin >> N >> K;

    for(int i = 1; i <= N; i++) cin >> kit[i];

    go(0);

    cout << ans << "\n";

    return 0;
}
