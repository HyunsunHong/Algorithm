#include<iostream>
using namespace std;
#define MAX 100001

int N, M, cnt=1, sum;
int book[MAX];

int main() {
	cin >> N >> M;
	if (N == 0) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> book[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		sum += book[i];
		if (sum > M) {
			cnt++;
			sum = book[i];
		}
	}
	cout << cnt << "\n";
}
