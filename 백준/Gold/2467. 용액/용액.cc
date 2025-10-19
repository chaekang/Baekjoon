#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int min = 2147000000;
	int start = 0;
	int end = n - 1;

	int a, b;
	while (start < end) {
		int val = v[start] + v[end];
		if (min >= abs(val)) {
			min = abs(val);
			a = v[start];
			b = v[end];
		}

		if (val < 0) {
			start++;
		}
		else if (val > 0) {
			end--;
		}
		else {
			break;
		}
	}

	cout << a << " " << b;
}