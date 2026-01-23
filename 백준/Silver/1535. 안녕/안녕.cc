#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int strength[21];
	int pleasure[21];
	for (int i = 0; i < n; i++)
	{
		cin >> strength[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> pleasure[i];
	}

	int dp[101] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 100; j >= strength[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - strength[i]] + pleasure[i]);
		}
	}

	cout << dp[99];
}