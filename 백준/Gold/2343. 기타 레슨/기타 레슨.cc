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
		if (mid < v[i]) return false;
		if (tmp < v[i])
		{
			tmp = mid;
			cnt++;
		}
		tmp -= v[i];
	}
	return m >= cnt;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	int start = 1;
	int end = 1000000;
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