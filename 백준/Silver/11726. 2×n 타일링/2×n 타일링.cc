#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int dp[1001];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	//dp[3] = 3;
	//dp[4] = 5;
	//dp[5] = 8;

	if (n <= 2)
	{
		cout << dp[n];
		return 0;
	}

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n];
}