#include <iostream>
#include <algorithm>
using namespace std;

int n;
int graph[501][501];
int dp[501][501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int DFS(int x, int y) {
	if (dp[x][y] != 0) return dp[x][y]; 

	dp[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (graph[nx][ny] > graph[x][y]) {
				dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
			}
		}
	}

	return dp[x][y];
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result = max(result, DFS(i, j));
		}
	}

	cout << result << '\n';
	return 0;
}
