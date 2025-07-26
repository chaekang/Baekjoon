#include <iostream>

using namespace std;

int n, m;
int r, c, d;
int room[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}

	int ans = 0;
	while (1) {
		if (room[r][c] == 0) {
			ans++;
			room[r][c] = 2;
		}
		bool clean = true;
		for (int i = 0; i < 4; i++) {
			int x = r + dx[i];
			int y = c + dy[i];

			if (room[x][y] == 0) {
				clean = false;
				break;
			}
		}

		if (clean) {  // 청소할데가 있으면
			int bx, by;
			if (d == 0) {
				bx = r + 1;
				by = c;
			}
			else if (d == 1) {
				bx = r;
				by = c - 1;
			}
			else if (d == 2) {
				bx = r - 1;
				by = c;
			}
			else {
				bx = r;
				by = c + 1;
			}

			if (room[bx][by] != 1) {
				r = bx;
				c = by;
			}
			else {
				cout << ans;
				return 0;
			}
		}
		else {  // 청소할 데가 없으면
			d = (d + 3) % 4;
			if (d == 0) {
				if (room[r - 1][c] == 0) {
					r = r - 1;
				}
			}
			else if (d == 1) {
				if (room[r][c + 1] == 0) {
					c = c + 1;
				}
			}
			else if (d == 2) {
				if (room[r + 1][c] == 0) {
					r = r + 1;
				}
			}
			else if (d == 3) {
				if (room[r][c - 1] == 0) {
					c = c - 1;
				}
			}
		}
	}
	cout << ans;
}