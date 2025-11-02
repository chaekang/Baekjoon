#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	priority_queue<long long, vector<long long>, greater<long long>> pq;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}

	for (int i = 0; i < m; i++) {
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();
		long long ab = a + b;
		pq.push(ab);
		pq.push(ab);
	}

	long long ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}

	cout << ans;
}