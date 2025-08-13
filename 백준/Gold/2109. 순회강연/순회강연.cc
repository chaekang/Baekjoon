#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int p, d;
		cin >> p >> d;
		v.push_back({ d, p });
	}

	sort(v.begin(), v.end());


	int ans = 0;
	for (int i = 0; i < n; i++) {
		pq.push(v[i].second);
		ans += v[i].second;

		if (pq.size() > v[i].first) {
			ans -= pq.top();
			pq.pop();
		}
	}
	cout << ans;
}