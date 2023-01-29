/*

  gold 4

greedy + sorting + sweeping

*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int> > lines;
int ans = 0;
int sp, ep;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> sp >> ep;

        lines.push_back(make_pair(sp, ep));
    }

    sort(lines.begin(), lines.end());    

    sp = lines[0].first;
    ep = lines[0].second;
    ans = 0;

    for(int i = 1; i < N; i++) {
        int next_sp = lines[i].first;
        int next_ep = lines[i].second;

        if(ep < next_sp) {
            ans += ep - sp;
            sp = next_sp;
            ep = next_ep;
        }
        else if(ep < next_ep) {
            ep = next_ep;
        }
     }

    ans += ep - sp;
    cout << ans;


    return 0;
}
