#include <iostream>

using namespace std;

int maze[1001][1001];
int dp[1001][1001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			dp[i][j] = maze[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] + maze[i][j]);
			if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] + maze[i][j]);
			if (i > 0 && j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + maze[i][j]);
		}
	}
	cout << dp[n - 1][m - 1];
}