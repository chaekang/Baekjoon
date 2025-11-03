#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
int ans = 999999999;
int map[101][101];
bool visited[101][101] = { false, };
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void FindLand(int i, int j, int count) {
	queue<pair<int, int>> q;
	map[i][j] = count;
	q.push({ i, j });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (map[nx][ny] == 1) {
					map[nx][ny] = count;
					q.push({ nx, ny });
				}
			}
		}
	}
}


void BFS(int num) {
	queue<pair<pair<int, int>, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == num) {
				visited[i][j] = true;
				q.push({ { i, j }, 0 });
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] != 0 && map[nx][ny] != num) {
				ans = min(ans, dist);
				return;
			}

			if (!visited[nx][ny] && map[nx][ny] == 0) {
				visited[nx][ny] = true;
				q.push({ {nx, ny}, dist + 1 });
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int count = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				FindLand(i, j, count);
				count++;
			}
		}
	}

	for (int i = 2; i < count; i++) {
		memset(visited, false, sizeof(visited));
		BFS(i);
	}

	cout << ans;
}