#include <iostream>
#include <queue>

using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

int main() {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, compare> pq;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x != 0) {
			pq.push(x);
		}
		else {
			if (pq.empty()) {
				v.push_back(0);
			}
			else {
				v.push_back(pq.top());
				pq.pop();
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}