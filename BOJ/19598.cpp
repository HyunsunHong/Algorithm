/*

  gold 5
  
  greedy + pq + sweepling

*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > pq;
vector<pair<int, int> > vec;
int ans = 0;

int main() {

    cin >> N;

    while(N--) {
        int sp, ep;

        cin >> sp >> ep;

        vec.push_back(make_pair(sp, ep));
    }

    sort(vec.begin(), vec.end());

    for(auto p : vec) {
        int sp = p.first;
        int ep = p.second;

        if(pq.empty()) {
            ans++;
            pq.push(ep);
        }
        else {
            if(pq.top() <= sp) {
                pq.pop();
                pq.push(ep);
            }
            else {
                ans++;
                pq.push(ep);
            }
        }   
    }

    cout << ans << "\n";

    return 0;
}
