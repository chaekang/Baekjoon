#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(pair<long long, long long> a, pair<long long, long long> b) {
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;

	vector<long long> length;
	vector<long long> grow;
	vector<pair<long long, long long>> tree;

	length.resize(n);
	grow.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> length[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> grow[i];
	}

	for (int i = 0; i < n; i++) {
		tree.push_back({ length[i], grow[i] });
	}

	sort(tree.begin(), tree.end(), cmp);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += tree[i].first + tree[i].second * i;
	}

	cout << ans;
}