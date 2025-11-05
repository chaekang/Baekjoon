#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int I, n;
vector<vector<int>> v;
vector<vector<bool>> visited;
pair<int, int> now;
pair<int, int> dest;

int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

void BFS(int xx, int yy) {
	queue<pair<int, int>> q;
	q.push({ xx, yy });
	visited[xx][yy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == dest.first && y == dest.second) {
			cout << v[x][y] << "\n";
			break;
		}

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
					v[nx][ny] = v[x][y] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> I;
	for (int i = 0; i < I; i++) {
		cin >> n;
		v.clear();
		visited.clear();
		v.resize(n, vector<int>(n, 0));
		visited.resize(n, vector<bool>(n, false));

		cin >> now.first >> now.second;
		cin >> dest.first >> dest.second;

		BFS(now.first, now.second);
	}
}