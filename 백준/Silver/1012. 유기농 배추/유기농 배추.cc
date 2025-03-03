#include <iostream>
#include <queue>

using namespace std;

int t;
int m, n, k;
int x, y;

int graph[50][50];
bool visited[50][50];
queue<pair<int, int>> q;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

void Init();
void BFS(int xx, int yy, int n, int m);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int T = 0; T < t; T++) {
		cin >> m >> n >> k;
		int cnt = 0;

		Init();

		for (int j = 0; j < k; j++) {
			cin >> y >> x;
			graph[x][y] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] == 1 && visited[i][j] == false) {
					BFS(i, j, n, m);
					cnt++;
				}
			}
		}

		cout << cnt << '\n';
	}
}

void Init() {
	while (!q.empty()) {
		q.pop();
	}
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			graph[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

void BFS(int xx, int yy, int n, int m) {
	q.push({ xx, yy });

	// 큐에 값이 있으면 계속 반복 실행
	while (!q.empty()) {
		auto front = q.front();
		int x = front.first;
		int y = front.second;
		q.pop();
		visited[x][y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && graph[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}