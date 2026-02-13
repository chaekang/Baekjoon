#include <iostream>
#include<algorithm>

using namespace std;

int v[10001];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	int idx = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		if (v[i] < v[i + 1])
		{
			idx = i;
			break;
		}
	}

	if (idx == 0)
	{
		cout << "-1";
		return 0;
	}

	for (int i = n; i > idx; i--)
	{
		if (v[i] > v[idx])
		{
			swap(v[i], v[idx]);
			break;
		}
	}

	sort(v + idx + 1, v + n + 1);

	for (int i = 1; i <= n; i++)
	{
		cout << v[i] << " ";
	}
}