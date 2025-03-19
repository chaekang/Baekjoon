#include <iostream>

using namespace std;

int n, m;
int graph[9] = { 0 };
bool visited[9] = { false };

void DFS(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << graph[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			graph[cnt] = i;
			DFS(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	DFS(0);
}