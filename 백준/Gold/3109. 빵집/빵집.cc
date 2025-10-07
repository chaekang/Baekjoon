#include <iostream>
#include <vector>

using namespace std;

int r, c;
int ans = 0;
vector<vector<char>> v;
vector<vector<bool>> visited;

int dx[3] = { -1, 0, 1 };
int dy[3] = { 1, 1, 1 };

bool DFS(int x, int y) {
	visited[x][y] = true;

	if (y == c - 1) {
		ans++;
		return true;
	}

	for (int i = 0; i < 3; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
			if (v[nx][ny] != 'x' && !visited[nx][ny]) {
				if (DFS(nx, ny)) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> r >> c;

	v.resize(r, vector<char>(c));
	visited.resize(r, vector<bool>(c, false));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		DFS(i, 0);
	}

	cout << ans;
}