#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<bool> v(n + 1, false);

	for (int i = 2; i * i <= n; i++) {
		if (!v[i]) {
			for (int j = i * i; j <= n; j += i) {
				v[j] = true;
			}
		}
	}

	vector<int> prime;
	for (int i = 2; i <= n; i++) {
		if (!v[i]) {
			prime.push_back(i);
		}
	}

	int interval_num = 0;
	int start = 0;
	int end = 0;
	int ans = 0;

	while (end < prime.size()) {
		interval_num += prime[end];
		end++;

		while (interval_num > n && start < end) {
			interval_num -= prime[start];
			start++;
		}

		if (interval_num == n) {
			ans++;
		}
	}

	cout << ans;
}