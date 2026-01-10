#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, c;
	cin >> n >> c;
	map<int, pair<int, int>> m;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (m.count(x) == 0)
		{
			m[x] = { 1, i };
		}
		else
		{
			m[x].first++;
		}
	}

	vector < pair<int, pair<int, int>>> v;

	for (auto& p : m) 
	{
		v.push_back(p);
	}

	sort(v.begin(), v.end(), [](auto& a, auto& b) {
		if (a.second.first != b.second.first)
			return a.second.first > b.second.first; 
		return a.second.second < b.second.second;
	});

	for (auto& p : v) {
		int num = p.first;
		int cnt = p.second.first;
		while (cnt--) {
			cout << num << ' ';
		}
	}
}