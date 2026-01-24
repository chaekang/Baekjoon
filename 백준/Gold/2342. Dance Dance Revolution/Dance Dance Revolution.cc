#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int dp[100001][5][5];

int cost(int from, int to) 
{
	if (from == 0) return 2;
	if (from == to) return 1;
	if (abs(from - to) == 2) return 4;
	return 3;
}

int main()
{
	while (1)
	{
		int x;
		cin >> x;
		if (x == 0) break;
		v.push_back(x);
	}

	for (int i = 0; i <= v.size(); i++)
	{
		for (int l = 0; l < 5; l++)
		{
			for (int r = 0; r < 5; r++)
			{
				dp[i][l][r] = 1e9;
			}
		}
	}

	dp[0][0][0] = 0;

	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i];
		for (int l = 0; l < 5; l++)
		{
			for (int r = 0; r < 5; r++)
			{
				if (dp[i][l][r] == 1e9) continue;
				dp[i + 1][x][r] = min(dp[i + 1][x][r], dp[i][l][r] + cost(l, x));
				dp[i + 1][l][x] = min(dp[i + 1][l][x], dp[i][l][r] + cost(r, x));

			}
		}
	}

	int ans = 1e9;
	for (int l = 0; l < 5; l++)
		for (int r = 0; r < 5; r++)
			ans = min(ans, dp[v.size()][l][r]);

	cout << ans;
}