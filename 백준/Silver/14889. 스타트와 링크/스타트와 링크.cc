#include <iostream>
#include <cmath>

using namespace std;

int n;
int v[21][21];
bool visited[21];
int ans = 1e9;

void DFS(int idx, int cnt)
{
	if (cnt == n / 2)
	{
		int start = 0;
		int link = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (visited[i] && visited[j])
				{
					start += v[i][j] + v[j][i];
				}
				else if (!visited[i] && !visited[j])
				{
					link += v[i][j] + v[j][i];
				}
			}
		}

		ans = min(ans, abs(start - link));
		return;
	}

	for (int i = idx; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			DFS(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}

	DFS(0, 0);
	cout << ans;
}