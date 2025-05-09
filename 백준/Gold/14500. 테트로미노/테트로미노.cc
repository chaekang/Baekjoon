#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int ans = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void DFS(int x, int y, int depth, int sum) {
	sum += arr[x][y];

	if (depth == 4) {
		if (ans < sum) {
			ans = sum;
		}
		return;
	}
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (!visited[nx][ny]) {
				DFS(nx, ny, depth + 1, sum);
			}
		}
	}

	visited[x][y] = false;
}

void T(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int sum = arr[x][y];
		for (int j = 0; j < 4; j++) {
			if (j == i) {
				continue;
			}

			int nx = dx[j] + x;
			int ny = dy[j] + y;

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				sum += arr[nx][ny];
			}
		}
		if (sum > ans) {
			ans = sum;
		}
	}
}

int main() {
	cin >> n >> m;
	arr.resize(n, vector<int>(m));
	visited.resize(n, vector<bool>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			DFS(i, j, 1, 0);
			T(i, j);
		}
	}

	cout << ans;
}