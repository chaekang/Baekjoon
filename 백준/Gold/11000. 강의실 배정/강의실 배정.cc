#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> n;

	while (n--) {
		int start, end;
		cin >> start >> end;
		v.push_back({ start, end });
	}

	sort(v.begin(), v.end());

	pq.push(v[0].second);

	for (int i = 1; i < v.size(); i++) {
		if (pq.top() <= v[i].first) {
			pq.pop();
			pq.push(v[i].second);
		}
		else {
			pq.push(v[i].second);
		}
	}
	cout << pq.size();
}