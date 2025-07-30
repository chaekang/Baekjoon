#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long b, c;
	cin >> b >> c;

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		arr[i] -= b;
		ans++;
		if (arr[i] <= 0) {
			continue;
		}
		ans += (arr[i] / c);
		if (arr[i] % c != 0) {
			ans += 1;
		}
	}
	cout << ans;
}