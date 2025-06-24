#include <iostream>

using namespace std;

long long dp[110];

long long DP(int x) {
	if (x <= 5) {
		return dp[x];
	}

	for (int i = 6; i <= x; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	return dp[x];
}

int main() {
	int t;
	cin >> t;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		cout << DP(n) << "\n";
	}
}