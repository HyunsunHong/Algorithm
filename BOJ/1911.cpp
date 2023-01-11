/*

    silver 1

    greedy + implementation


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
int tip = 0;
int ans = 0;
vector<pair<int, int> > v;

int main() {


    cin >> N >> L;

    for(int i = 0; i < N; i++) {
        int s, e;

        cin >> s >> e;

        v.push_back(make_pair(s, e));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        int s = v[i].first;
        int e = v[i].second;

        if(tip <= s) {
            int length = e - s;
            
            if(length % L == 0) {
                ans += length/L;
                tip = e;
            }
            else {
                ans += length/L + 1;
                tip = s +(length/L + 1)*L;
            }
        }
        else {
            if(e <= tip) continue;
            s = tip;

            int length = e - s;
            
            if(length % L == 0) {
                ans += length/L;
                tip = e;
            }
            else {
                ans += length/L + 1;
                tip = s + (length/L + 1)*L;
            }

        }
    }   

    cout << ans << "\n";

    return 0;
}