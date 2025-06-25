#include <iostream>

using namespace std;
int zero[41];
int one[41];

void DP(int x) {
	if (x <= 1) {
		cout << zero[x] << " " << one[x] << "\n";
		return;
	}

	for (int i = 2; i <= x; i++) {
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}
	cout << zero[x] << " " << one[x] << "\n";
}

int main() {
	int t;
	cin >> t;

	zero[0] = 1;
	zero[1] = 0;
	one[0] = 0;
	one[1] = 1;

	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		DP(x);
	}
}