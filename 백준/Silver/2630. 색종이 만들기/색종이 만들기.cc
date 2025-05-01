#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;
int blue = 0;
int white = 0;

void ColorPaper(int x, int y, int k) {
	bool cut = false;
	int firstColor = paper[x][y];
	for (int i = x; i < k + x; i++) {
		for (int j = y; j < k + y; j++) {
			if (paper[i][j] != firstColor) {
				cut = true;
				break;
			}
		}
	}

	if (cut) {
		ColorPaper(x, y, k / 2);
		ColorPaper(x + k / 2, y, k / 2);
		ColorPaper(x, y + k / 2, k / 2);
		ColorPaper(x + k / 2, y + k / 2, k / 2);
	}
	else {
		if (firstColor == 0) {
			white++;
		}
		else {
			blue++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	paper.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	ColorPaper(0, 0, n);
	cout << white << "\n" << blue;
}