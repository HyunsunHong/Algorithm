/*
  
  gold 5
  
  bfs + set

*/

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, k;
set<string> s;
string obj;
string curr;
vector<int> v;

int bfs() {
    if(curr.compare(obj) == 0) return 0;

    queue<pair<string, int> >q;
    q.push(make_pair(curr, 0));

    while(!q.empty()) {
        curr = q.front().first;
        int cnt = q.front().second;

        q.pop();

        for(int i = 0; i + k - 1 < curr.size(); i++) {
            string next;

            for(int j = 0; j < i; j++) {
                next.push_back(curr[j]);
            }
            for(int j = i + k - 1; j >= i; j--) {
                next.push_back(curr[j]);
            }
            for(int j = i + k; j < curr.size(); j++) {
                next.push_back(curr[j]);
            }

            //cout << "next " << next << "\n";

            if(s.find(next) == s.end()) {
                if(next.compare(obj) == 0) return cnt + 1;
                else {
                    s.insert(next);
                    q.push(make_pair(next, cnt + 1));
                }
            }
        }
    }


    return -1;
}

int main() {

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int inp;

        cin >> inp;

        curr.push_back('0' + inp);
        v.push_back(inp);
    }

    sort(v.begin(), v.end());
    for(auto x : v) {
        obj.push_back(x + '0');
    }

    cout << bfs();

    return 0;
}
