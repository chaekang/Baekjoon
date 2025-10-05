#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, b;
	cin >> n >> m >> b;

	vector<vector<int>> v(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int time = 0;
	int minTime = 999999999;
	int height = 0;

	for (int h = 0; h <= 256; h++) {
		int remove = 0;
		int add = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (v[i][j] < h) {
					add += h - v[i][j];
				}
				else if (v[i][j] == h) {
					continue;
				}
				else if (v[i][j] > h) {
					remove += v[i][j] - h;
				}
			}
		}

		if (b + remove >= add) {
			time = remove * 2 + add;

			if (time <= minTime) {
				minTime = time;
				height = h;
			}
		}
	}

	cout << minTime << " " << height;
}