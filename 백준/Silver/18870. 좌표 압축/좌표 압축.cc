#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	int idx = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back({ idx, x });
		idx++;
	}

	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	});

	idx = 0;
	vector<pair<int, int>> ans(n);
	ans[0].first = v[0].first;
	ans[0].second = idx;
	for (int i = 1; i < n; i++) {
		if (v[i - 1].second < v[i].second) {
			idx++;
		}
		ans[i].first = v[i].first;
		ans[i].second = idx;
	}

	sort(ans.begin(), ans.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.first < b.first;
	});

	for (int i = 0; i < n; i++) {
		cout << ans[i].second << " ";
	}
}