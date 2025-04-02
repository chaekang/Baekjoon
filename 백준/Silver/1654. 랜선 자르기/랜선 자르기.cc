#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int k, n;
	cin >> k >> n;

	vector<ll> line(k);
	for (int i = 0; i < k; i++) {
		cin >> line[i];
	}

	sort(line.begin(), line.end());

	ll start = 1;
	ll end = line[k - 1];
	ll ans = 0;

	while (start <= end) {
		ll cut = (start + end) / 2;
		ll count = 0;

		for (int i = 0; i < k; i++) {
			count += line[i] / cut;
		}

		if (count < n) {
			end = cut - 1;
		}
		else {
			ans = cut;
			start = cut + 1;
		}
	}

	cout << ans;
}