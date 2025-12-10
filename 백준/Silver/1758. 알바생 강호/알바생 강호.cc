#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	long long ans = 0;
	sort(v.begin(), v.end(), greater<long long>());
	for (long long i = 0; i < n; i++)
	{
		long long tmp = v[i] - i;
		if (tmp > 0)
		{
			ans += tmp;
		}
	}
	cout << ans;
}