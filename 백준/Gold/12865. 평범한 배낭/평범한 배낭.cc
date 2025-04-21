#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<pair<int, int>> bag;
vector<vector<int>> dp;

int main() {

	cin >> n >> k;
	bag.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> bag[i].first >> bag[i].second;
	}

	dp.resize(n + 1, vector<int>(k + 1, 0));

	for (int i = 1; i <= n; i++) {
		int curWeight = bag[i].first;
		int curValue = bag[i].second;

		for (int j = 0; j <= k; j++) {
			if (j >= curWeight) {
				dp[i][j] = max(dp[i - 1][j - curWeight] + curValue, dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][k];
}