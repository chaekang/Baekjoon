#include <iostream>

using namespace std;

int parent[10001];
int cost[10001];
int minCost[10001];

int find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}

	return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		parent[b] = a;
	}
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
		parent[i] = i;
		minCost[i] = cost[i];
	}

	for (int i = 0; i < m; i++)
	{
		int v, w;
		cin >> v >> w;
		unite(v, w);
	}

	for (int i = 1; i <= n; i++)
	{
		int root = find(i);
		minCost[root] = min(minCost[root], cost[i]);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (parent[i] == i)
		{
			ans += minCost[i];
		}
	}

	if (ans <= k)
	{
		cout << ans;
	}
	else
	{
		cout << "Oh no";
	}
}