#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<vector<int>> graph;
vector<bool> visited;
queue<int> q;

void BFS(int x) {
	q.push(x);
	visited[x] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	int cnt = 0;

	graph.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			BFS(i);
			cnt++;
		}
	}
	cout << cnt;
}