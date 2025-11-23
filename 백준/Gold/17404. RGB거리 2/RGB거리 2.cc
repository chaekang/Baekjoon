#include <iostream>
#include <algorithm>

using namespace std;

int arr[1002][3];
int dp[1002][3];
int ans = 987654321;

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	for (int rgb = 0; rgb <= 2; rgb++) {
		for (int i = 0; i <= 2; i++) {
			if (i == rgb)
				dp[1][i] = arr[1][i];
			else
				dp[1][i] = 987654321;
		}

		for (int i = 2; i <= n; i++) {
			dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}

		for (int i = 0; i <= 2; i++) {
			if (i == rgb) continue;
			else ans = min(ans, dp[n][i]);
		}
	}
	cout << ans;
}