#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> pq;

	int n, m, k;
	vector<int> satisfy;
	int day = 0;

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	satisfy.push_back(0);

	while (!pq.empty()) {
		int top = pq.top();
		pq.pop();

		if (top <= k) {
			break;
		}

		day++;
		satisfy.push_back(satisfy[day - 1] / 2 + top);
		if (top > k) {
			pq.push(top - m);
		}
	}

	cout << day << "\n";
	for (int i = 1; i < satisfy.size(); i++) {
		cout << satisfy[i] << "\n";
	}
}