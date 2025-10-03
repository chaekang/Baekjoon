#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	stack<char> s;
	string str;
	cin >> str;

	int tmp = 1;
	int ans = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			tmp *= 2;
			s.push('(');
		}
		else if (str[i] == '[') {
			tmp *= 3;
			s.push('[');
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				ans = 0;
				break;
			}

			if (str[i - 1] == '(') {
				ans += tmp;
			}
			tmp /= 2;
			s.pop();
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				ans = 0;
				break;
			}

			if (str[i - 1] == '[') {
				ans += tmp;
			}
			tmp /= 3;
			s.pop();
		}
	}

	if (!s.empty()) {
		ans = 0;
	}

	cout << ans;
}