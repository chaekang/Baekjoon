#include <iostream>

using namespace std;

int main() {
	int t;
	long long dp[106];
	cin >> t;

	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;

	for (int i = 6; i < 105; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}