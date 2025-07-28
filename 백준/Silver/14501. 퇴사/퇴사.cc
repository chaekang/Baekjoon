#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int day[15] = { 0, };
	int money[15] = { 0, };
	int dp[15] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> day[i] >> money[i];
	}

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		dp[i] = max(ans, dp[i]);
		if (day[i] + i <= n) {
			dp[day[i] + i] = max(dp[day[i] + i], money[i] + dp[i]);
		}
		ans = max(ans, dp[i]);
	}

	cout << ans;
}