#include <iostream>

using namespace std;

int main() {
	string n;
	cin >> n;

	int numbers[10] = { 0, };

	for (int i = 0; i < n.length(); i++) {
		int x = n[i] - '0';
		if (x == 6 && numbers[6] > numbers[9]) {
			numbers[9]++;
		}
		else if (x == 9 && numbers[9] > numbers[6]) {
			numbers[6]++;
		}
		else {
			numbers[x]++;
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (ans < numbers[i]) {
			ans = numbers[i];
		}
	}

	cout << ans;
}