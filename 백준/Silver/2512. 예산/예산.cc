#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;

	vector<int> request(n);
	ll sum = 0;
	ll ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> request[i];
		sum += request[i];
	}
	sort(request.begin(), request.end());

	ll m;
	cin >> m;

	if (sum <= m) {
		ans = request[n - 1];
	}
	else {
		ll start = 0;
		ll end = request[n - 1];

		while (start <= end) {
			ll mid = (start + end) / 2;
			sum = 0;

			for (int i = 0; i < n; i++) {
				if (request[i] <= mid) {
					sum += request[i];
				}
				else {
					sum += mid;
				}
			}

			if (sum < m) {
				start = mid + 1;
				ans = mid;
			}
			else if (sum > m) {
				end = mid - 1;
			}
			else {
				ans = mid;
				break;
			}
		}
	}

	cout << ans;
}