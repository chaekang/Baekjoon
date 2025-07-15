#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

pair<ll, ll> dots[1501];

ll getDist(pair<ll, ll> a, pair<ll, ll> b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return dx * dx + dy * dy;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> dots[i].first >> dots[i].second;
	}

	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				ll x = getDist(dots[i], dots[j]);
				ll y = getDist(dots[j], dots[k]);
				ll z = getDist(dots[i], dots[k]);

				if (x > y) {
					swap(x, y);
				}
				if (y > z) {
					swap(y, z);
				}
				if (x > y) {
					swap(x, y);
				}
				if (z == x + y) {
					ans++;
				}
			}
		}
	}
	cout << ans;
}