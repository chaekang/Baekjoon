#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
vector<int> ans;
int cnt = 0;

void DFS(int x) {
	visited[x] = true;
	cnt++;
	ans[x] = cnt;

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) {
			DFS(y);
		}
	}
}

int main() {
	int n, m, r;
	cin >> n >> m >> r;

	visited.resize(n + 1, false);
	graph.resize(n + 1);
	ans.resize(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(r);

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << "\n";
	}
}