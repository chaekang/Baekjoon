#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		vector<int> stock;

		cin >> n;
		stock.resize(n);

		for (ll i = 0; i < n; i++) {
			cin >> stock[i];
		}

		ll ans = 0;
		ll k = n - 1;
		for (ll i = n - 2; i >= 0; i--) {
			if (stock[i] < stock[k]) {
				ans += (stock[k] - stock[i]);
			}
			else {
				k = i;
			}
		}

		cout << ans << "\n";
	}
}