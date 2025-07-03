#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int ans = 0;

	for (int i = 2; i <= n; i++) {
		if (i % 5 == 0) {
			ans++;
			if (i % 25 == 0) {
				ans++;
			}
			if (i % 125 == 0) {
				ans++;
			}
		}
	}

	cout << ans;
}