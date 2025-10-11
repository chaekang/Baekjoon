#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v;
	vector<int> multiTap(n, 0);

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int ans = 0;
	for (int i = 0; i < k; i++) {
		bool yes = false;
		for (int j = 0; j < n; j++) {
			if (multiTap[j] == v[i]) {
				yes = true;
				break;
			}
		}
		if (yes) {
			continue;
		}

		for (int j = 0; j < n; j++) {
			if (multiTap[j] == 0) {
				multiTap[j] = v[i];
				yes = true;
				break;
			}
		}
		if (yes) {
			continue;
		}

		int last = -1;
		int index = -1;
		for (int j = 0; j < n; j++) {
			int tmp = 0;
			for (int t = i + 1; t < k; t++) {
				if (multiTap[j] == v[t]) {
					break;
				}
				tmp++;
			}

			if (tmp > last) {
				last = tmp;
				index = j;
			}
		}

		multiTap[index] = v[i];
		ans++;
	}
	cout << ans;
}