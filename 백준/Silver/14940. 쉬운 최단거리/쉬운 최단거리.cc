#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1001][1001];
int ans[1001][1001];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

queue<pair<int, int>> q;

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			ans[i][j] = -1;

			if (map[i][j] == 2) {
				q.push({ i, j });
				ans[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (ans[nx][ny] != -1) continue;
			if (map[nx][ny] == 0) continue;

			ans[nx][ny] = ans[cur.first][cur.second] + 1;

			q.push({ nx,ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << 0 << " ";
			}
			else {
				cout << ans[i][j] << " ";
			}
		}
		cout << "\n";
	}
}