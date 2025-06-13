#include <iostream>
#include <queue>

using namespace std;

int n, m;
int graph[501][501];
bool visited[501][501];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ans = 0;
int sz = 0;
int maxSize = 0;

void BFS(int xx, int yy) {
	queue<pair<int, int>> q;
	q.push({ xx, yy });
	visited[xx][yy] = true;
	sz = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (!visited[nx][ny] && graph[nx][ny] == 1) {
					q.push({ nx, ny });
					visited[nx][ny] = true;
					sz++;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && graph[i][j] == 1) {
				BFS(i, j);
				ans++;

				if (sz > maxSize) {
					maxSize = sz;
				}
			}
		}
	}

	cout << ans << "\n" << maxSize;
}