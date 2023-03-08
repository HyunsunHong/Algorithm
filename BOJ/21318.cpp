/*
  
  silver 1
  
  prefix sum

*/

#include <iostream>

using namespace std;

int N, Q;
int arr[100001] = {0, };
int sum[100001] = {0, };

int main() {
    ios::sync_with_stdio(false);
	  cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i < N; i++) {
        if(arr[i] > arr[i + 1]) sum[i] = 1;
        
        sum[i] += sum[i - 1];
    }   

    cin >> Q;

    for(int i = 0; i < Q; i++) {
        int x, y;

        cin >> x >> y;

        cout << sum[y - 1] - sum[x - 1] << "\n";
    }

    return 0;
} 
