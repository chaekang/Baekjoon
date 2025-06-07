#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int graph[50][50];
bool visited[50][50];
int dx[8] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int dy[8] = { -1, 1, 1, 0, -1, 1, 0, -1 };

void BFS(int h, int w, int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny >= 0 && nx >= 0 && ny < h && nx < w) {
				if (!visited[ny][nx] && graph[ny][nx] == 1) {
					q.push({ ny, nx });
					visited[ny][nx] = true;
				}
			}
		}
	}
}

int main() {
	while (true) {
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		memset(graph, 0, sizeof(graph));
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> graph[i][j];
			}
		}

		int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && graph[i][j] == 1) {
					BFS(h, w, i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
