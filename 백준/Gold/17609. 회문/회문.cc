#include <iostream>
#include <string>

using namespace std;

string s;

int isPalindrome(int left, int right, bool test) {
	while (left < right) {
		if (s[left] != s[right]) {
			if (test) {
				if (isPalindrome(left + 1, right, false) == 0 || isPalindrome(left, right - 1, false) == 0 ) {
					return 1;
				}
			}
			return 2;
		}
		left++;
		right--;
	}
	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;

	cin >> t;

	while (t--) {
		cin >> s;
		cout << isPalindrome(0, s.length() - 1, true) << "\n";
	}
}