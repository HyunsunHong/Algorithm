/*
  platinum 5
  
  divide and conquer

*/

#include <iostream>

using namespace std;

int N;
long long arr[100001];

long long histo(int lo, int hi) {
    if(lo == hi) return arr[lo];

    int mid = (lo + hi)/2;

    long long left = histo(lo, mid);
    long long right = histo(mid + 1, hi);

    long long result = max(left, right);

    int l = mid;
    int h = mid;
    long long curr = arr[mid];
    result = max(result, arr[l]);

    while(lo < l || h < hi) {
        if(l == lo) h++;
        else if(h == hi) l--;
        else if(arr[l - 1] >= arr[h + 1]) l--;
        else h++;

        curr = min(curr, arr[l]);
        curr = min(curr, arr[h]);
        result = max(result,  curr * (h - l + 1));
    }

    return result;
}

int main() {

    cin >> N;

    for(int i = 1; i <= N; i++) cin >> arr[i];

    cout << histo(1, N) << "\n";

    return 0;
}
