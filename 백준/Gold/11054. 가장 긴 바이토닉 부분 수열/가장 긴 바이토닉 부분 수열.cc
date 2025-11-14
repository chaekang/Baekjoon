#include <iostream>
#include <vector>

using namespace std;

int up[1001];
int down[1001];

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		up[i] = 1;
		down[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				up[i] = max(up[i], up[j] + 1);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= i; j--) {
			if (v[i] > v[j]) {
				down[i] = max(down[i], down[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, up[i] + down[i] - 1);
	}

	cout << ans;
}