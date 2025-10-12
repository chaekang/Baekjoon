#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	int a[26] = { 0, };

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		int value = 1;
		for (int j = s.size() - 1; j >= 0; j--) {
			a[s[j] - 'A'] += value;
			value *= 10;
		}
	}

	sort(a, a + 26, cmp);

	int num = 9;
	int ans = 0;

	for (int i = 0; i < 26; i++) {
		if (a[i] == 0) {
			break;
		}

		ans += a[i] * (num--);
	}
	cout << ans;
}