#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector<int> seats(n + 1);
	vector<int> vip(n + 1);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> vip[i];
	}

	seats[0] = 1;
	seats[1] = 1;
	seats[2] = 2;

	for (int i = 3; i <= n; i++) {
		seats[i] = seats[i - 1] + seats[i - 2];
	}

	int idx = 1;
	int ans = 1;

	for (int i = 0; i < m; i++) {
		ans *= seats[vip[i] - idx];
		idx = vip[i] + 1;
	}

	ans *= seats[n + 1 - idx];

	cout << ans;
}