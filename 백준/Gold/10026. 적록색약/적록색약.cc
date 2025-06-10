#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char graph[101][101];
bool visited[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n;

void NotColorBlind(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (!visited[nx][ny] && graph[x][y] == graph[nx][ny]) {
					q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
		}
	}
}

void ColorBlind(int xx, int yy) {
	queue<pair<int, int>> q;
	q.push({ xx, yy });
	visited[xx][yy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (!visited[nx][ny]) {
					if (graph[xx][yy] == graph[nx][ny]) {
						q.push({ nx, ny });
						visited[nx][ny] = true;
					}
					else if ((graph[nx][ny] == 'G' && graph[xx][yy] == 'R') || (graph[nx][ny] == 'R' && graph[xx][yy] == 'G')) {
						q.push({ nx, ny });
						visited[nx][ny] = true;
					}
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			visited[i][j] = false;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				NotColorBlind(i, j);
				ans++;
			}
		}
	}

	cout << ans << " ";

	ans = 0;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				ColorBlind(i, j);
				ans++;
			}
		}
	}

	cout << ans;
}