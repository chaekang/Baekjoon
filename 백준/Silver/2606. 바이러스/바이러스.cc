#include <iostream>
#include <vector>

using namespace std;

int n, m;
int cnt = 0;
vector<vector<int>> graph;
vector<bool> visited;

void DFS(int);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> m;

	int a, b;

	graph.resize(n + 1);
	visited.resize(n + 1, false);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1);

	cout << cnt << "\n";
}

void DFS(int x) {
	visited[x] = true;

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) {
			cnt++;
			DFS(y);
		}
	}
}