#include <iostream>

using namespace std;

int parent[201];
int plan[1001];

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
		parent[a] = b;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a;
			cin >> a;
			if (a == 1)
			{
				unite(i, j);
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> plan[i];
	}

	int root = find(plan[0]);
	for (int i = 1; i < m; i++)
	{
		if (find(plan[i]) != root)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}