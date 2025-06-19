#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 99999999

int n, m;
int graph[101][101];
int dist[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Maze() {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 0 });
	dist[0][0] = 0;

	while (!pq.empty()) {
		int x = pq.top().first;
		int y = pq.top().second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (graph[nx][ny] == 0) {
					if (dist[nx][ny] > dist[x][y]) {
						dist[nx][ny] = dist[x][y];
						pq.push({ nx, ny });
					}
				}
				else if (graph[nx][ny] == 1) {
					if (dist[nx][ny] > dist[x][y] + 1) {
						dist[nx][ny] = dist[x][y] + 1;
						pq.push({ nx, ny });
					}
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;

	string str;
	for (int i = 0; i < m; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			graph[i][j] = str[j] - '0';
			dist[i][j] = INF;
		}
	}

	Maze();
	cout << dist[m - 1][n - 1] << "\n";
	return 0;
}