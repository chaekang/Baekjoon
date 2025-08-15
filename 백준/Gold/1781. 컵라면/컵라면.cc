#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue <int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> v;
	
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		pq.push(v[i].second);
		ans += v[i].second;

		if (v[i].first < pq.size()) {
			ans -= pq.top();
			pq.pop();
		}
	}

	cout << ans;
}