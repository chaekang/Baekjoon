#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int n;
		cin >> n;
		int count = 0;
		for (int j = 0; j < n; j++) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			if (pow(cx - x1, 2) + pow(cy - y1, 2) < pow(r, 2) && pow(cx - x2, 2) + pow(cy - y2, 2) > pow(r, 2)) {
				count++;
			}
			if (pow(cx - x1, 2) + pow(cy - y1, 2) > pow(r, 2) && pow(cx - x2, 2) + pow(cy - y2, 2) < pow(r, 2)) {
				count++;
			}
		}
		cout << count << "\n";
	}
}