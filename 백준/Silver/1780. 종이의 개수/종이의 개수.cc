#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> arr;
int result[3] = { 0, };

bool Check(int row, int col, int size) {
	int start = arr[row][col];
	
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (start != arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void Divide(int row, int col, int size) {
	if (Check(row, col, size)) {
		result[arr[row][col]]++;
		return;
	}

	int newSize = size / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Divide(row + newSize * i, col + newSize * j, newSize);
		}
	}
}

int main() {
	cin >> n;
	arr.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			arr[i][j] = x + 1;
		}
	}
	Divide(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << result[i] << "\n";
	}

}