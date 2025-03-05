#include <iostream>

using namespace std;

int N, M;
int graph[500][500];
int visited[500][500];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int DFS(int x, int y) {
	if (x == N - 1 && y == M - 1) {
		return 1;
	}

	if (visited[x][y] == -1) {
		visited[x][y] = 0;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (graph[nx][ny] < graph[x][y]) {
					visited[x][y] += DFS(nx, ny);
				}
			}
		}
	}
	return visited[x][y];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			visited[i][j] = -1;
		}
	}

	cout << DFS(0, 0);
}