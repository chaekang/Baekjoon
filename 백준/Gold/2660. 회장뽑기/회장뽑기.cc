#include <iostream>
#include <vector>

using namespace std;

#define INF 9999
int friends[51][51];
int dist[51][51];

int main() {
	int n;
	cin >> n;


	while (1) {
		int x, y;
		cin >> x >> y;
		if (x == -1 && y == -1) {
			break;
		}
		friends[x][y] = 1;
		friends[y][x] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (friends[i][j] != 0) {
				dist[i][j] = friends[i][j];
			}
			else if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = INF;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dist[j][k] = min(dist[j][k], dist[i][k] + dist[j][i]);
			}
		}
	}

	int score = INF;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		int maxLen = 0;
		for (int j = 1; j <= n; j++) {
			if (maxLen < dist[i][j] && dist[i][j] != 0) {
				maxLen = dist[i][j];
			}
		}

		if (score > maxLen) {
			score = maxLen;
			ans.clear();
		}

		if (score == maxLen) {
			ans.push_back(i);
		}
	}

	cout << score << " " << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}