#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int set[100];

int parent(int x) {
    if(set[x] == x) return x;
    return set[x] = parent(set[x]);
} 

void Union(int a, int b) {
    a = parent(a);
    b = parent(b);
    
    if(a < b) set[b] = a;
    else set[a] = b;
}

bool is_Union(int a, int b) {
    return parent(a) == parent(b);
}

bool cmp(vector<int> c1, vector<int> c2) {
    return c1[2] <= c2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i = 0; i < n; i++) set[i] = i;
    
    for(auto c : costs) {
        if(!is_Union(c[0], c[1])) {
            Union(c[0], c[1]);
            answer += c[2];
        } 
    }
    
    return answer;
}
