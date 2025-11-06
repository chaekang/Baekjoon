#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int l, r, c, ans;
char v[31][31][31];
bool visited[31][31][31] = { false, };
int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int df[6] = { 0, 0, 0, 0, 1, -1 };
pair<pair<int, int>, int> start, fin;

int BFS(int ff, int xx, int yy) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { ff, xx }, { yy, 0 } });
	visited[ff][xx][yy] = true;

	while (!q.empty()) {
		int f = q.front().first.first;
		int x = q.front().first.second;
		int y = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (f == fin.first.first && x == fin.first.second && y == fin.second) {
			return cnt;
		}

		for (int i = 0; i < 6; i++) {
			int nf = f + df[i];
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nf >= 0 && nx >= 0 && ny >= 0 && nf < l && nx < r && ny < c) {
				if (v[nf][nx][ny] == '#') continue;
				if (!visited[nf][nx][ny]) {
					if (v[nf][nx][ny] == '.' || v[nf][nx][ny] == 'E') {
						visited[nf][nx][ny] = true;
						q.push({ {nf, nx}, {ny, cnt + 1} });
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	while (true) {
		ans = 0;
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) {
			break;
		}

		memset(visited, false, sizeof(visited));
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> v[i][j][k];

					if (v[i][j][k] == 'S') {
						start.first.first = i;
						start.first.second = j;
						start.second = k;
					}
					else if (v[i][j][k] == 'E') {
						fin.first.first = i;
						fin.first.second = j;
						fin.second = k;
					}
				}
			}
		}
		ans = BFS(start.first.first, start.first.second, start.second);
		if (ans != -1) {
			cout << "Escaped in " << ans << " minute(s).\n";
		}
		else {
			cout << "Trapped!\n";
		}
	}
}