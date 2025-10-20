#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int gcdVal = arr[1] - arr[0];
	for (int i = 2; i < n; i++) {
		gcdVal = gcd(gcdVal, arr[i] - arr[i - 1]);
	}

	vector<int> ans;
	for (int i = 2; i <= gcdVal; i++) {
		if (gcdVal % i == 0) {
			ans.push_back(i);
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}