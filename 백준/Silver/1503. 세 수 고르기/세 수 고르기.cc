#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int n, m;
int cmp = 1000000000;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i < 1002; i++) {
		arr.push_back(i);
	}

	cin >> n >> m;

	while (m--) {
		int num;
		cin >> num;
		arr.erase(remove(arr.begin(), arr.end(), num), arr.end());
	}

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			for (int k = 0; k < arr.size(); k++) {
				int cal = arr[i] * arr[j] * arr[k];
				if (abs(n - cal) < cmp) {
					cmp = abs(n - cal);
				}
				if (n + 1 < cal)
					break;
			}
		}
	}

	cout << cmp;
}