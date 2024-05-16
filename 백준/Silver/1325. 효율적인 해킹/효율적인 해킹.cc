#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> graph;
bool visited[10001];

int cnt = 0;

void DFS(int x) {

	visited[x] = true;
	cnt++;

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) {
			DFS(y);
		}
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	graph.resize(n + 1);

	vector<int> result_count(n + 1, 0);
	int max = 0;

	while (m--) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		cnt = 0;
		DFS(i);
		result_count[i] = cnt;
		if (cnt > max) {
			max = cnt;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (result_count[i] == max) {
			cout << i << " ";
		}
	}
}