#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	ll n;
	ll ans;

	cin >> n;
	vector<ll> dp(n + 1);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[n] % 15746;
}