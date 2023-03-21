/*
  
   silver 4
   
   dp
*/

#include <iostream>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
    int TC, N,  maxSum;
    scanf("%d", &TC);
    while (TC--) {
        memset(dp, 0, sizeof(dp));
        maxSum = INT_MIN;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
        }


        for (int i = 1; i <= N; i++) {
            dp[i] = arr[i];
            if (arr[i] + dp[i - 1] > dp[i]) {
                dp[i] = arr[i] + dp[i - 1];
            }
            maxSum = max(maxSum, dp[i]);
        }

        printf("%d\n", maxSum);

    }

    return 0;
}
