#include <iostream>

using namespace std;

void Star(int i, int j, int size) {
	if ((i / size) % 3 == 1 && (j / size) % 3 == 1) {
		cout << " ";
	}
	else {
		if (size / 3 == 0) {
			cout << "*";
		}
		else {
			Star(i, j, size / 3);
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Star(i, j, n);
		}
		cout << "\n";
	}
}