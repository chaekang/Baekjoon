#include <iostream>

using namespace std;

int dp[201][201] = { 0, };
const int MOD = 1000000000;

int main() {
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i <= k; i++) {
		dp[0][i] = 1;
	}


	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			for (int m = 0; m <= i; ++m) {
				dp[i][j] = (dp[i][j] + dp[m][j - 1]) % MOD;
			}
		}
	}

	cout << dp[n][k];
}