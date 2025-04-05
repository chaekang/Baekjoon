#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int n, c;
	cin >> n >> c;

	vector<ll> house(n);

	for (int i = 0; i < n; i++) {
		cin >> house[i];
	}

	sort(house.begin(), house.end());

	ll ans = 0;
	ll start = 1;
	ll end = house[n - 1] - house[0];

	while (start <= end) {
		ll mid = (start + end) / 2;
		ll cur = house[0];
		int cnt = 1;

		for (int i = 1; i < n; i++) {
			if (house[i] - cur >= mid) {
				cur = house[i];
				cnt++;
			}
		}

		if (cnt < c) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			ans = mid;
		}
	}

	cout << ans;
}