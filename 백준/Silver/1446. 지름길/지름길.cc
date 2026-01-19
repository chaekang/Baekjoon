#include <iostream>
#include <vector>

using namespace std;

int dp[10005];
vector<pair<int, int>> v[10005];

int main()
{
	int n, d;
	cin >> n >> d;

	int from, to, cost;
	for (int i = 0; i < n; i++)
	{
		cin >> from >> to >> cost;
		v[to].push_back({ from, cost });
	}

	dp[0] = 0;
	for (int i = 1; i <= d; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < v[i].size(); j++)
		{
			dp[i] = min(dp[i], dp[v[i][j].first] + v[i][j].second);
		}
	}

	cout << dp[d];
}