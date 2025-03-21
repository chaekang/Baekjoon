#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> arr;
vector<int> oper(4);
int maxAns = INT_MIN;
int minAns = INT_MAX;

void Operation(int ans, int idx) {
	if (idx == n) {
		maxAns = max(ans, maxAns);
		minAns = min(ans, minAns);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			if (i == 0) {
				Operation(ans + arr[idx], idx + 1);
			}
			else if (i == 1) {
				Operation(ans - arr[idx], idx + 1);
			}
			else if (i == 2) {
				Operation(ans * arr[idx], idx + 1);
			}
			else {
				Operation(ans / arr[idx], idx + 1);
			}
			oper[i]++;
		}
	}
}

int main() {
	cin >> n;

	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}

	Operation(arr[0], 1);

	cout << maxAns << "\n" << minAns;
}