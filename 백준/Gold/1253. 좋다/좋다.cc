#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int start = 0;
		int end = n - 1;
		int hap = 0;
		while (start < end) {
			if (start == i) {
				start++;
				continue;
			}
			if (end == i) {
				end--;
				continue;
			}

			if (v[start] + v[end] > v[i]) {
				end--;
			}
			else if (v[start] + v[end] < v[i]) {
				start++;
			}
			else {
				ans++;
				break;
			}
		}
	}

	cout << ans;
}