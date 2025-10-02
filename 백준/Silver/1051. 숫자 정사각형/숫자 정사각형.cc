#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 1; i + k < n && j + k < m; k++) {
				if (arr[i][j] == arr[i + k][j] &&
					arr[i][j] == arr[i][j + k] &&
					arr[i][j] == arr[i + k][j + k]) {
					ans = max(ans, k + 1);
				}
			}
		}
	}

	cout << ans * ans;
}