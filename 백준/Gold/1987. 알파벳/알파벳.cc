#include <iostream>
#include <vector>

using namespace std;

int r, c;
vector<vector<char>> board;
vector<bool> visited(26);
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int result = 0;

void DFS(int x, int y, int cnt) {
	visited[board[x][y] - 'A'] = true;
	result = max(cnt, result);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < c && ny < r) {
			if (!visited[board[nx][ny] - 'A']) {
				DFS(nx, ny, cnt + 1);
			}
		}
	}
	visited[board[x][y] - 'A'] = false;
}

int main() {
	cin >> r >> c;
	board.resize(c + 1, vector<char>(r + 1));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[j][i];
		}
	}
	DFS(0, 0, 1);
	cout << result;
}