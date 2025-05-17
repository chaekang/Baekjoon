#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool arr[101];

	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		arr[i] = val;
	}

	int k;
	cin >> k;
	vector<pair<int, int>> student(k);

	for (int i = 0; i < k; i++) {
		cin >> student[i].first >> student[i].second;
	}

	for (int i = 0; i < k; i++) {
		int num = student[i].second;
		if (student[i].first == 1) {
			for (int j = 1; j <= n; j++) {
				if (j % num == 0) {
					arr[j] = !arr[j];
				}
			}
		}
		else {
			int left = num, right = num;
			while (left - 1 >= 1 && right + 1 <= n && arr[left - 1] == arr[right + 1]) {
				left--;
				right++;
			}
			for (int j = left; j <= right; j++) {
				arr[j] = !arr[j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
}