#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ll m, n;
	vector<ll> tree;
	ll ans = 0;
	
	cin >> n >> m;

	tree.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	sort(tree.begin(), tree.end());

	ll low = 0;
	ll high = tree[n - 1];

	while (low <= high) {
		ll cut = (low + high) / 2;
		ll left = 0;
		for (int i = 0; i < n; i++) {
			if (cut < tree[i]) {
				left += tree[i] - cut;
			}
		}

		if (left >= m) {
			ans = cut;
			low = cut + 1;
		}
		else {
			high = cut - 1;
		}
	}

	cout << ans;
}