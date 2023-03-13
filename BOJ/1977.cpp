/*
  
  bronze 2
  
  bruteforce

*/

#include <iostream>

using namespace std;

int N, M;
bool is_absolute[10001] = {false, };

int main() {

    cin >> N >> M;
    int sum = 0;
    int min_val = -1;

    for(int i = 1; i*i <= 10000; i++) {
            is_absolute[i*i] = true;
        }


    for(int i = N; i <= M; i++) {
        if(is_absolute[i]) {
            sum += i;
            if(min_val == -1) min_val = i;
        }
    }

    if(min_val != -1) {
        cout << sum << "\n" << min_val << "\n";
    }
    else cout << -1 << "\n";

    return 0;
}
