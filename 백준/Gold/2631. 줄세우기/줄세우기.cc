#include <iostream>

using namespace std;

int v[201];
int dp[201];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		if (ans < dp[i]) {
			ans = dp[i];
		}
	}
	cout << n - ans;
}