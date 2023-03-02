/*
  
  gold 2
  
  math

*/

#include <iostream>
#define MAX 2000001

using namespace std;

int N;
long long school[MAX] = {0, };
long long ans = 0;

int main() {

    cin >> N;

    while(N--) {
        long long inp;
        cin >> inp;
        school[inp]++;
    }

    for(int team_num = 1; team_num < MAX; team_num++) {
        long long school_cnt = 0;
        for(int i = 1; i * team_num < MAX; i++) {
            school_cnt += school[team_num * i];
        }

        if(school_cnt >= 2) {
            ans = max(ans, school_cnt * team_num);
        }
    }

    cout << ans << "\n";

    return 0;
}
