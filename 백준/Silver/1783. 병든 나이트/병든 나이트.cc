#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int ans;
	if (n == 1)
	{
		ans = 1;
	}
	else if (n == 2)
	{
		ans = min(4, (m - 1) / 2 + 1);
	}
	else
	{
		if (m >= 7)
		{
			ans = m - 2;
		}
		else
		{
			ans = min(4, m);
		}
	}
	cout << ans;
}