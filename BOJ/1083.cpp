/* 

  gold 5
  
  greedy 

*/

#include <iostream>

using namespace std;

int N;
int arr[51];
int S;
int start_idx = 1;

int main() {

    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    cin >> S;

    for(int i = 1; i <= N; i++) {
        int max_val = arr[i];
        int max_idx = i;

        for(int j = i + 1; j <= min(N, i + S); j++) {
            if(max_val < arr[j]) {
                max_val = arr[j];
                max_idx = j;
            }
        }

        S -= max_idx - i;
        for(int j = max_idx; j > i; j--) {
            swap(arr[j], arr[j - 1]);
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
