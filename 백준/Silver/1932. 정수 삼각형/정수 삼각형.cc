#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<int>> triangle(n, vector<int>(n));
	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	dp[0][0] = triangle[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else if (j == 0) {
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < dp[n - 1][i]) {
			ans = dp[n - 1][i];
		}
	}

	cout << ans;
}