#include <iostream>
#include <vector>

using namespace std;
#define INF 999999

int n, m;
vector<vector<int>> friends;

int main() {
	cin >> n >> m;
	friends.resize(n + 1, vector<int>(n + 1, INF));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		friends[a][b] = 1;
		friends[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (friends[j][i] + friends[i][k] < friends[j][k]) {
					friends[j][k] = friends[j][i] + friends[i][k];
				}
			}
		}
	}

	int value = INF;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			tmp += friends[i][j];
		}
		if (tmp < value) {
			value = tmp;
			ans = i;
		}
	}

	cout << ans;
}