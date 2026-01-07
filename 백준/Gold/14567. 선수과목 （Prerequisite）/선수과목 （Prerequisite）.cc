#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[1001];
int degree[1001];
int ans[1001];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		degree[b]++;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
			ans[i] = 1;
		}
	}

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int y : v[x])
		{
			ans[y] = max(ans[y], ans[x] + 1);

			if (--degree[y] == 0)
			{
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
}