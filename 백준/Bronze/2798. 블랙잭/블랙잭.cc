#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	int ans = 0;

	cin >> n >> m;
	vector<int> cards(n);

	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int prevAns = cards[i] + cards[j] + cards[k];
				if (prevAns <= m && prevAns > ans) {
					ans = prevAns;
				}
			}
		}
	}

	cout << ans;
}