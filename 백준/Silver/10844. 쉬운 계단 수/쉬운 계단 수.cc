#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long dp[101][10];
	long long MOD = 1000000000;

	cin >> n;

	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	dp[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] % MOD;
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
		dp[i][9] = dp[i - 1][8] % MOD;
	}

	long long cnt = 0;
	for (int i = 0; i <= 9; i++) {
		cnt = cnt + dp[n][i];
	}

	cout << cnt % MOD << "\n";
}