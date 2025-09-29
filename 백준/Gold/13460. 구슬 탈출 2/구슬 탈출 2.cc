#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Marble {
	int rx, ry;
	int bx, by;
	int count;
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char v[11][11];
bool visited[11][11][11][11];

void Move(int& rx, int& ry, int& distance, int& i)
{
	while (v[rx + dx[i]][ry + dy[i]] != '#' && v[rx][ry] != 'O')
	{
		rx += dx[i];
		ry += dy[i];
		distance += 1;
	}
}

void Maze(int Rx, int Ry, int Bx, int By) {
	queue<Marble> q;
	q.push({ Rx, Ry, Bx, By });
	visited[Rx][Ry][Bx][By] = true;

	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int count = q.front().count;
		q.pop();

		if (count >= 10) break;

		for (int i = 0; i < 4; i++) {
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0, ncount = count + 1;

			Move(nrx, nry, rc, i);
			Move(nbx, nby, bc, i);

			if (v[nbx][nby] == 'O') continue;
			if (v[nrx][nry] == 'O')
			{
				cout << ncount;
				return;
			}

			if (nrx == nbx && nry == nby)
			{
				if (rc > bc) nrx -= dx[i], nry -= dy[i];
				else nbx -= dx[i], nby -= dy[i];
			}

			if (visited[nrx][nry][nbx][nby]) continue;
			visited[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby,ncount });
		}
	}
	cout << -1;
}

int main() {
	int n, m;
	cin >> n >> m;
	pair<int, int> red;
	pair<int, int> blue;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'R') {
				red = { i, j };
			}
			else if (v[i][j] == 'B') {
				blue = { i, j };
			}
		}
	}

	Maze(red.first, red.second, blue.first, blue.second);
}