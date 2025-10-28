#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[32010];
int entry[32010];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		entry[b]++;
	}

	priority_queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (entry[i] == 0) {
			q.push(-i);
		}
	}

	while (q.empty() == 0) {
		int cur = -q.top();
		q.pop();
		cout << cur << " ";

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			entry[next]--;

			if (entry[next] == 0) {
				q.push(-next);
			}
		}
	}
	cout << "\n";
}