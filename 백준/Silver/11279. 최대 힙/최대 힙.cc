#include <iostream>
#include <queue>

using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	int x;
	cin >> n;

	priority_queue<int, vector<int>, less<int>> q;

	while (n--) {
		cin >> x;

		if (x == 0) {
			if (q.empty()) {
				cout << "0\n";
			}
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
}