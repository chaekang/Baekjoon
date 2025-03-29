#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;

	vector<int> ans;

	for (int i = m; i <= n; i++) {
		if (i < 2) {
			continue;
		}

		bool isPrime = true;

		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime) {
			ans.push_back(i);
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}