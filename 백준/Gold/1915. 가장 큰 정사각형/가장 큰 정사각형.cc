#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	string inp;
	int maxLen = 0;
	cin >> n >> m;

	vector<vector<int>> square(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; i++) {
		cin >> inp;
		for (int j = 0; j < inp.length(); j++) {
			square[i][j + 1] = inp[j] - '0';
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (square[i][j] == 1) {
				square[i][j] = min(square[i - 1][j - 1], min(square[i - 1][j], square[i][j - 1])) + 1;
				if (maxLen < square[i][j]) {
					maxLen = square[i][j];
				}
			}
		}
	}

	cout << maxLen * maxLen << "\n";
}