#include <iostream>

using namespace std;

int n;
int chess[15];
int result = 0;

int Promising(int row) {
	for (int i = 0; i < row; i++) {
		if (chess[row] == chess[i] || abs(row - i) == abs(chess[row] - chess[i])) {
			return 0;
		}
	}
	return 1;
}

void NQueen(int row) {
	if (row == n) {
		result++;
		return;
	}

	for (int i = 0; i < n; i++) {
		chess[row] = i;
		if (Promising(row)) {
			NQueen(row + 1);
		}
	}
}

int main(void) {
	cin >> n;
	NQueen(0);
	cout << result;
}