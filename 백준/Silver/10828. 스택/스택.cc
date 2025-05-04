#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	string command;
	int x, ans = 0;
	stack<int> stack;

	for (int i = 0; i < n; i++) {
		cin >> command;

		if (command == "push") {
			cin >> x;
			stack.push(x);
		}
		else if (command == "pop") {
			if (stack.empty()) {
				ans = -1;
			}
			else {
				ans = stack.top();
				stack.pop();
			}
			cout << ans << "\n";
		}
		else if (command == "size") {
			ans = stack.size();
			cout << ans << "\n";
		}
		else if (command == "empty") {
			if (stack.empty()) {
				ans = 1;
			}
			else {
				ans = 0;
			}
			cout << ans << "\n";
		}
		else {
			if (stack.empty()) {
				ans = -1;
			}
			else {
				ans = stack.top();
			}
			cout << ans << "\n";
		}
	}
}