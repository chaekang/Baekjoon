#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> answer;

void BFS() {
	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int parent = q.front();
		q.pop();

		for (int i = 0; i < graph[parent].size(); i++) {
			int child = graph[parent][i];
			if (!visited[child]) {
				visited[child] = true;
				answer[child] = parent;
				q.push(child);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int a, b;

	cin >> n;

	graph.resize(n + 1);
	visited.resize(n + 1, false);
	answer.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	BFS();

	for (int i = 2; i <= n; i++) {
		cout << answer[i] << "\n";
	}
}