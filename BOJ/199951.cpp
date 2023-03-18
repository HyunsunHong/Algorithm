/*
  
  gold 5
  
  prefix sum

*/

#include <iostream>

using namespace std;

int N, M;
long long sum[100002];
long long height[100002];

int main() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> height[i];
    }

    while(M--) {
        int a, b;
        long long k;

        cin >> a >> b >> k;

        sum[a] += k;
        sum[b + 1] += -k; 
    }

    for(int i = 1; i <= N; i++) {
        sum[i] += sum[i - 1];
        height[i] += sum[i];
    }

    for(int i = 1; i <= N; i++) {
        cout << height[i] << " ";
    }

    return 0;
}
