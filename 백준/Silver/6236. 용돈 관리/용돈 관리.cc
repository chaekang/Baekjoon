#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

bool Check(int mid)
{
	int tmp = mid;
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (v[i] > mid) return false;

		if (v[i] > tmp)
		{
			cnt++;
			tmp = mid;
		}

		tmp -= v[i];
	}
	return cnt <= m;
}

int main()
{
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int start = 1;
	int end = 1000000000;
	int ans = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (Check(mid))
		{
			end = mid - 1;
			ans = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	cout << ans;
}