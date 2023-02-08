/*
    platinum 4

    greedy + LIS(nlgn)

*/

#include <iostream>
#include <set>

using namespace std;

int m, n, k;
int ans;
set<pair<int, int> > s;

int main() {

    cin >> m >> n >> k;

    for(int i = 0; i < k; i++) {
        int r, c;

        cin >> r >> c;

        s.insert(make_pair(r, c));
    }

    while(!s.empty()) {
        ans++;
        pair<int, int> p = *s.begin();

        s.erase(s.begin());

        auto it = s.begin();
        while(it != s.end()) {
            if(p.first <= it->first && p.second <= it->second) {
                p = *it;
                s.erase(it++);
            }
            else {
                it++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
