#include <iostream>
#include <string.h>

using namespace std;

char map[3072][6144];

const char triangle[][5] = {
	' ', ' ', '*', ' ', ' ',
	' ', '*', ' ', '*', ' ',
	'*', '*', '*', '*', '*'
};

void makeTriangle(int len, int x, int y) {
	if (len == 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				map[x + i][y + j] = triangle[i][j];
			}
		}
		return;
	}

	int t = 3 * len / 2;

	makeTriangle(len / 2, x, y + t);
	makeTriangle(len / 2, x + t, y);
	makeTriangle(len / 2, x + t, y + 2 * t);
}

int main() {
	int n;
	cin >> n;

	memset(map, ' ', sizeof(map));
	makeTriangle(n / 3, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
}