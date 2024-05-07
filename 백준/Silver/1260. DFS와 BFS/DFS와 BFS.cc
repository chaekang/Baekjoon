#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> dfs_visited;
vector<bool> bfs_visited;

void DFS(int);
void BFS(int);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, v;

	cin >> n >> m >> v;

	graph.resize(n + 1);
	dfs_visited.resize(n + 1, false);
	bfs_visited.resize(n + 1, false);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < graph.size(); i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(v);
	cout << "\n";
	BFS(v);
	cout << "\n";
}

void DFS(int x) {
	dfs_visited[x] = true;
	cout << x << " ";

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!dfs_visited[y]) {
			dfs_visited[y] = true;
			DFS(y);
		}
	}
}

void BFS(int x) {
	queue<int> q;
	q.push(x);
	bfs_visited[x] = true;

	while (!q.empty()) {
		int y = q.front();
		q.pop();
		cout << y << " ";

		for (int i = 0; i < graph[y].size(); i++) {
			if (!bfs_visited[graph[y][i]]) {
				q.push(graph[y][i]);
				bfs_visited[graph[y][i]] = true;
			}
		}
	}

}