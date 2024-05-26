#include <iostream>

using namespace std;

int n;
int ls[100001];
int dp[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ls[i];
		dp[i] = ls[i];
	}

	int maxInt = dp[0];

	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i], dp[i - 1] + ls[i]);
		if (dp[i] > maxInt) {
			maxInt = dp[i];
		}
	}

	cout << maxInt << "\n";
}