#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> vec;
int N;

int main() {

    cin >> N;

    for(int i = 0; i < N; i++) {
        int input;
        cin >> input;

        vec.push_back(input);
    }

    sort(vec.begin(), vec.end());

    int ans = 0;

    int lowwest_end = 0;
    int higgest_end = N - 1;

    while(lowwest_end <= N - 1 && vec[0] == vec[lowwest_end]) lowwest_end++;
    lowwest_end--;
    while(higgest_end >= 0 && vec[N - 1] == vec[higgest_end]) higgest_end--;
    higgest_end++;

    
    if(vec[N - 1] - vec[0] > 17) {
        int diff = vec[N - 1] - vec[0];

        int least_side = min(lowwest_end + 1, N - higgest_end);

        ans = pow(diff, 2)*least_side;
    }

    cout << ans << "\n";

    return 0;
}