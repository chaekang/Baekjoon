#include <iostream>

using namespace std;

int arr[2001];
int dp[2001][2001] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
	}

	for (int i = 1; i <= n - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}

	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i - 2; j++) {
			if (arr[i] == arr[j] && dp[j + 1][i - 1]) {
				dp[j][i] = 1;
			}
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}
}