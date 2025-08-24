#include <iostream>

using namespace std;

int r, c, k;
char map[6][6];
bool visited[6][6] = { false, };

int dx[4] = {-1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1 };

int ans = 0;

void DFS(int x, int y, int dist) {
	if (dist == k && x == 0 && y == c - 1) {
		ans++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] == 'T') {
			continue;
		}

		if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
			continue;
		}

		if (visited[nx][ny]) {
			continue;
		}

		visited[nx][ny] = true;
		DFS(nx, ny, dist + 1);
		visited[nx][ny] = false;
	}
}

int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	visited[r - 1][0] = true;
	DFS(r - 1, 0, 1);
	cout << ans;

}