#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int hap = v[0];
	int start = 0;
	int end = 0;
	int ans = n + 1;
	while (start <= end && end < n) {
		if (hap < s) {
			end++;
			hap += v[end];
		}
		else {
			ans = min(ans, end - start + 1);
			hap -= v[start];
			start++;
		}
	}

	if (ans == n + 1) {
		cout << 0;
	}
	else {
		cout << ans;
	}
}