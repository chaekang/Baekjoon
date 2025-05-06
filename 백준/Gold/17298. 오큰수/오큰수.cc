#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> ans(n, -1);
	stack<int> stack;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		while (!stack.empty() && arr[stack.top()] < arr[i]) {
			ans[stack.top()] = arr[i];
			stack.pop();
		}
		stack.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}