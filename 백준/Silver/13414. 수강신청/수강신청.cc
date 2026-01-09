#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int k, l;
	cin >> k >> l;
	map<string, int>m;
	vector<pair<int, string>>v;

	for (int i = 0; i < l; i++)
	{
		string n;
		cin >> n;
		m[n] = i + 1;
	}

	for (auto i = m.begin(); i != m.end(); i++) {
		string a = i->first;
		int b = i->second;
		v.push_back({ b, a });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < min(k, (int)v.size()); i++) {
		cout << v[i].second << "\n";
	}
}