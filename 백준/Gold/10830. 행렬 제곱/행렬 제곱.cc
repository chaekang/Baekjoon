#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll b;
ll matrix[5][5];
ll ans[5][5];
ll tmp[5][5];

void MatrixMultiply(ll x[5][5], ll y[5][5]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				tmp[i][j] += (x[i][k] * y[k][j]);
			}
			tmp[i][j] %= 1000;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = tmp[i][j];
		}
	}
}

int main() {

	cin >> n >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
		ans[i][i] = 1;
	}

	while (b > 0) {
		if (b % 2 == 1) {
			MatrixMultiply(ans, matrix);
		}
		MatrixMultiply(matrix, matrix);
		b /= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}