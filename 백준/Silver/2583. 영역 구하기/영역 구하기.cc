#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k;
bool visited[101][101] = { false, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int cnt = 0;
vector<int> ans;

void BFS(int xx, int yy) {
	queue<pair<int, int>> q;
	q.push({ xx , yy });
	visited[xx][yy] = true;
	int count = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
				if (!visited[nx][ny]) {
					q.push({ nx, ny });
					visited[nx][ny] = true;
					count++;
				}
			}

		}
	}
	ans.push_back(count);
}

int main() {
	cin >> m >> n >> k;

	for (int e = 0; e < k; e++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				visited[j][i] = true;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				BFS(i, j);
				cnt++;
			}
		}
	}
	
	cout << cnt << "\n";
	sort(ans.begin(), ans.end());

	for (int i = 0; i < cnt; i++) {
		cout << ans[i] << " ";
	}
}