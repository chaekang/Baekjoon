#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main()
{
	cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	int ans = 0;
	vector<int> DP;

	for (int i = 1; i <= n; i++) {
		auto IT = lower_bound(DP.begin(), DP.end(), v[i]);
		int Index = IT - DP.begin();

		if (IT == DP.end()) {
			DP.push_back(v[i]);
		}
		else {
			*IT = v[i];
		}
	}

	ans = (int)DP.size();

	cout << ans;
}