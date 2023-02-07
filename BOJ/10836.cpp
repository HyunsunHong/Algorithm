/*

    gold 4

    implementation + simulation

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int M, N;
    
    cin >> M >> N;

    vector<long long> border(2*M - 1);

    for(int i = 0; i < 2*M - 1; i++) border[i] = 1;

    while(N--) {
        int zero, one, two;

        cin >> zero >> one >> two;

        for(int i = zero; i < zero + one; i++) border[i]++;
        for(int i = zero + one; i < 2*M - 1; i++) border[i] += 2;
    }

    for(int r = 0; r < M; r++) {
        for(int c = 0; c < M; c++) {
            if(c == 0) cout << border[M - 1 - r] << " ";
            else cout << border[M - 1 + c] << " ";
        }
        cout << "\n";
    }

    return 0;
}
