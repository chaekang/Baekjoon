#include <iostream>

using namespace std;

int paper[100][100] = { 0, };

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				paper[j][k] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			ans += paper[i][j];
		}
	}

	cout << ans;
}