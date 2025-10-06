#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[1001];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > ans) {
			break;
		}
		ans += arr[i];
	}

	cout << ans;
}