#include <iostream>

using namespace std;

int main() {
	for (int i = 0; i < 4; i++) {
		int x1, y1, p1, q1, x2, y2, p2, q2;
		cin >> x1 >> y1 >> p1 >> q1 >> x2 >> y2 >> p2 >> q2;

		if (p1 < x2 || p2 < x1 || q1 < y2 || q2 < y1) {
			cout << "d" << "\n";
		}
		else if ((p1 == x2 && q2 == y1) || (x1 == p2 && y1 == q2) || (x1 == p2 && q1 == y2) || (x2 == p1 && y2 == q1)) {
			cout << "c" << "\n";
		}
		else if (x2 == p1 || y2 == q1 || x1 == p2 || y1 == q2) {
			cout << "b" << "\n";
		}
		else {
			cout << "a" << "\n";
		}
	}
}