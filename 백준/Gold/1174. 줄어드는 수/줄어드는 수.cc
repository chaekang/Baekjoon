#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;
	if (n > 1023) {
		cout << "-1\n";
		return 0;
	}

	long long arr[1023];

	int index = 0;

	for (int i = 0; i < 10; i++) {
		arr[index++] = i;
	}
	for (int i = 1; i < 1022; i++) {
		long long tmp = arr[i];
		for (int j = 0; j < 10; j++) {
			if (tmp % 10 > j) {
				arr[index++] = tmp * 10 + j;
			}
		}
	}

	cout << arr[n - 1] << "\n";

	return 0;
}