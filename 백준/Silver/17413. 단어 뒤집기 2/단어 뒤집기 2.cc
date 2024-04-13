#include <iostream>
#include <stack>
#include <string>

using namespace std;

void PrintStack(stack<char> &stack) {
	while (!stack.empty()) {
		cout << stack.top();
		stack.pop();
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<char> stack;
	string s;

	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			PrintStack(stack);
			while (1) {
				cout << s[i];
				if (s[i] == '>') {
					break;
				}
				i++;
			}
		}
		else if (s[i] == ' ') {
			PrintStack(stack);
			cout << " ";
		}
		else {
			stack.push(s[i]);
		}
	}
	PrintStack(stack);
}