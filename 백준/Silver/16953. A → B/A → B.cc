#include <iostream>
#include <queue>

using namespace std;

long long a, b;

void Find(long long x, int y) {
	queue<pair<long long, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		long long cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == b) {
			cout << cnt + 1;
			return;
		}

		if (cur * 2 <= b) {
			q.push({ cur * 2, cnt + 1 });
		}
		
		if (cur * 10 + 1 <= b) {
			q.push({ cur * 10 + 1, cnt + 1 });
		}
	}

	cout << "-1";
}

int main() {
	cin >> a >> b;

	Find(a, 0);
}