#include <iostream>
#include <queue>

using namespace std;

int n, m;
char campus[601][601];
bool visited[601][601];
pair<int, int> IPos;
int ans = 0;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void BFS() {
	queue<pair<int, int>> q;
	q.push(IPos);
	visited[IPos.first][IPos.second] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (visited[nx][ny] || campus[nx][ny] == 'X') {
					continue;
				}
				if (campus[nx][ny] == 'P') {
					ans++;
				}
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> campus[i][j];  // 올바른 행-열 순서로 입력
			if (campus[i][j] == 'I') {
				IPos.first = i;  // 시작 좌표 설정
				IPos.second = j;
			}
		}
	}

	BFS();

	if (ans == 0) {
		cout << "TT";
	}
	else {
		cout << ans;
	}

	return 0;
}
