#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, x;
	vector<int> atm;

	cin >> n;
	atm.resize(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> atm[i];
	}

	sort(atm.begin(), atm.end());

	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			ans += atm[j];
		}
	}

	cout << ans;
}