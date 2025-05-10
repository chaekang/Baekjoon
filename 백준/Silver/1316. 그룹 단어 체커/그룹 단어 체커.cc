#include <iostream>

using namespace std;

int main() {
	int n;
	int ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		bool used[26] = { false, };
		bool check = false;

		cin >> str;

		used[str[0] - 'a'] = true;
		for (int i = 1; i < str.length(); i++) {
			if (str[i] == str[i - 1]) {
				continue;
			}
			if (used[str[i] - 'a']) {
				check = true;
			}
			used[str[i] - 'a'] = true;
		}

		if (!check) {
			ans++;
		}
	}

	cout << ans;
}