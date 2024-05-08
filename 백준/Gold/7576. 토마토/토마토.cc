#include <iostream>
#include <queue>

using namespace std;

int m, n;
int tomato[1001][1001];
queue<pair<int, int>> q;
int x_dir[4] = { -1, 1,0,0 };
int y_dir[4] = { 0,0,-1,1 };

void BFS() {
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = a + x_dir[i];
			int y = b + y_dir[i];

			if (x >= 0 && x < n && y >= 0 && y < m && tomato[x][y] == 0) {
				tomato[x][y] = tomato[a][b] + 1;
				q.push(make_pair(x, y));
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	BFS();

	int result = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}
			if (result < tomato[i][j]) {
				result = tomato[i][j];
			}
		}
	}
	cout << result - 1 << "\n";
}