#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int cnt = 1;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0 ,-1, 0, 1 };
char v[101][101];
bool visited[101][101];
vector<int> ans;

void DFS(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx > 0 && ny > 0 && nx <= n && ny <= m) {
			if (v[nx][ny] == '#' && !visited[nx][ny]) {
				cnt++;
				DFS(nx, ny);
			}
		}
	}
}

bool compare(int x, int y) {
	return x > y;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			v[i][j] = '.';
		}
	}

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		v[x][y] = '#';
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (v[i][j] == '#' && !visited[i][j]) {
				cnt = 1;
				DFS(i, j);
				ans.push_back(cnt);
			}
		}
	}

	sort(ans.begin(), ans.end(), compare);
	cout << ans[0];
}