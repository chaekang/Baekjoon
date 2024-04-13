#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int x;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> q;

	while (n--) {
		cin >> x;

		if (x == 0) {
			if (!q.empty()) {
				cout << q.top() << "\n";
				q.pop();
			}
			else {
				cout << "0\n";
			}
		}
		else {
			q.push(x);
		}
	}
	return 0;
}