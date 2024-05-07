#include <iostream>
#include <queue>

using namespace std;

int maze[101][101];
bool visited[101][101];
int arc[101][101];

int n, m;
int cnt = 0;

int x_dir[4] = { -1,1,0,0 };
int y_dir[4] = { 0,0,-1,1 };

void BFS(int x, int y) {
	queue<pair<int, int>> q;

	visited[x][y] = true;
	q.push(make_pair(x, y));
	arc[x][y] += 1;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = a + x_dir[i];
			int new_y = b + y_dir[i];

			if ((0 <= new_x && new_x < n) && (new_y >= 0 && new_y < m)
				&& !visited[new_x][new_y] && maze[new_x][new_y] == 1) {
				
				visited[new_x][new_y] = true;
				q.push(make_pair(new_x, new_y));
				arc[new_x][new_y] = arc[a][b] + 1;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			maze[i][j] = s[j] - '0';
		}
	}

	BFS(0, 0);
	cout << arc[n - 1][m - 1];
}