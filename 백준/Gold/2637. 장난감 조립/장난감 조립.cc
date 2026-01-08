#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> v[101];
int degree[101];
int dp[103][103];
int basic[103];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y, k;
		cin >> x >> y >> k;
		v[y].push_back(make_pair(x, k));
		degree[x]++;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
		{
			basic[i] = 1;
			q.push(i);
			dp[i][i] = 1;
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto next : v[cur])
		{
			degree[next.first]--;
			if (degree[next.first] == 0)
				q.push(next.first);

			for (int j = 1; j <= n; j++)
			{
				dp[next.first][j] += dp[cur][j] * next.second;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (basic[i])
			cout << i << ' ' << dp[n][i] << '\n';
	}
}