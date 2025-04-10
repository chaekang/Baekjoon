#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 9999999

int n, m, k, x;
vector<int> graph[300001];
vector<int> ans;

void Dijkstra() {
	queue<int> q;
	q.push(x);
	ans[x] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (ans[next] > ans[cur] + 1) {
				ans[next] = ans[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	ans.resize(n + 1, INF);

	Dijkstra();

	bool in = false;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == k) {
			in = true;
			cout << i << "\n";
		}
	}

	if (!in) {
		cout << "-1";
	}
}