#include <iostream>

using namespace std;

string video[64];

void QuadTree(int size, int y, int x) {
	char cur = video[y][x];

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (video[i][j] != cur) {
				cout << "(";
				QuadTree(size / 2, y, x);
				QuadTree(size / 2, y, x + size / 2);
				QuadTree(size / 2, y + size / 2, x);
				QuadTree(size / 2, y + size / 2, x + size / 2);
				cout << ")";
				return;
			}
		}
	}
	cout << cur;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> video[i];
	}

	QuadTree(n, 0, 0);
}