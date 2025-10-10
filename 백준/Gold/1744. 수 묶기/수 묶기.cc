#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> plus;
	vector<int> minus;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > 0) {
			plus.push_back(x);
		}
		else {
			minus.push_back(x);
		}
	}
	sort(plus.begin(), plus.end(), greater<int>());
	sort(minus.begin(), minus.end());

	int ans = 0;
	for (int i = 0; i + 1 < plus.size(); i += 2) {
		if (plus[i + 1] == 1) {
			ans += plus[i] + plus[i + 1];
		}
		else {
			ans += plus[i] * plus[i + 1];
		}
	}
	if (plus.size() % 2 == 1) {
		ans += plus.back();
	}

	for (int i = 0; i + 1 < minus.size(); i += 2) {
		ans += minus[i] * minus[i + 1];
	}
	if (minus.size() % 2 == 1) {
		ans += minus.back();
	}

	cout << ans;
}