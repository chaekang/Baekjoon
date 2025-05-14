#include <iostream>

using namespace std;

int plane[101][101] = { 0, };

int main() {

	for (int i = 0; i < 4; i++) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			for (int j = x1 + 1; j <= x2; j++) {
				for (int k = y1 + 1; k <= y2; k++) {
					plane[j][k] = 1;
				}
			}
	}

	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			ans += plane[i][j];
		}
	}

	cout << ans;
}