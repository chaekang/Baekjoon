#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> heavier, lighter;
vector<bool> visited;
vector<int> result;

int DFS(int x, vector<vector<int>> &graph) {
	visited[x] = true;
	int count = 0;

	for (int i = 0; i < graph[x].size(); i++) {
		int next = graph[x][i];
		if (!visited[next]) {
			count++;
			count += DFS(next, graph);
		}
	}
	return count;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cin >> m;

	heavier.resize(n + 1);
	lighter.resize(n + 1);
	result.resize(n + 1, 0);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		heavier[x].push_back(y);
		lighter[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		visited.assign(n + 1, false);
		int heavierCount = DFS(i, heavier);

		visited.assign(n + 1, false);
		int lighterCount = DFS(i, lighter);

		result[i] = n - 1 - (heavierCount + lighterCount);
		cout << result[i] << "\n";
	}
}