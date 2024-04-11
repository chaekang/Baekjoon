#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));
vector<pair<int, int>> blank;
bool finish = false;

bool check(int x, int y, int n) {
	for (int i = 0; i < 9; i++) {
		if (sudoku[x][i] == n) {
			return false;
		}
		else if (sudoku[i][y] == n) {
			return false;
		}
	}

	int div_x = (x / 3) * 3;
	int div_y = (y / 3) * 3;
	for (int i = div_x; i < div_x + 3; i++) {
		for (int j = div_y; j < div_y + 3; j++) {
			if (sudoku[i][j] == n) {
				return false;
			}
		}
	}

	return true;
}


void Sudoku(int n) {
	cout.tie(0);

	if (finish) {
		return;
	}

	if (n == blank.size()) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << " ";
			}
			cout << "\n";
		}
		finish = true;
	}
	else {
		int x = blank[n].first;
		int y = blank[n].second;

		for (int i = 1; i <= 9; i++) {

			if (check(x, y, i)) {
				sudoku[x][y] = i;
				Sudoku(n + 1);
				sudoku[x][y] = 0;
			}

		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] == 0) {
				blank.push_back(make_pair(i, j));
			}
		}
	}

	Sudoku(0);
	
	return 0;
}