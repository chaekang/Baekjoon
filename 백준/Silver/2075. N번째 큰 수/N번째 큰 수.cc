#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int x;
	priority_queue<int, vector<int>, greater<int>> q;

	cin >> n;
	int n2 = pow(n, 2);

	while(n2--) {
		cin >> x;
		
		if (q.size() < n) {
			q.push(x);
		}
		else {
			if (q.top() < x) {
				q.pop();
				q.push(x);
			}
		}
	}

	cout << q.top();
}