#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	int n, m;
	int a, b;

	cin >> t;

	while (t--) {
		cin >> n >> m;

		while (m--) {
			cin >> a >> b;
		}
		cout << n - 1 << "\n";
	}
}