#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 1;
	int up = 1;
	int down = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] < arr[i]) {
			up++;
			down = 1;
		}
		else if (arr[i - 1] > arr[i]) {
			down++;
			up = 1;
		}
		else {
			up++;
			down++;
		}
		ans = max(ans, max(up, down));
	}

	cout << ans;
}