#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[101];
long long dp[101][21];

int main()
{
	int N , lastNumber;
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> arr[i];
	}
	cin >> lastNumber;

	dp[0][arr[0]] = 1;

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 0; j < 21 ; j++)
		{
			if (dp[i - 1][j] == 0) continue;

			if (j + arr[i] <= 20)
			{
				dp[i][j + arr[i]] += dp[i - 1][j];
			}
			if (j - arr[i] >= 0)
			{
				dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[N - 2][lastNumber];
}