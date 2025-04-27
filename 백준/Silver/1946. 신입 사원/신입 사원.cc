#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int t, n, a, b;
	vector<pair<int, int>> newbie;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		newbie.clear();
		for (int j = 0; j < n; j++) {
			cin >> a >> b;
			newbie.push_back({ a, b });
		}

		sort(newbie.begin(), newbie.end());

		int ans = 1;
		int tmp = 0;
		for (int k = 1; k < n; k++) {
			if (newbie[k].second < newbie[tmp].second) {
				tmp = k;
				ans++;
			}
		}

		cout << ans << "\n";
	}
}