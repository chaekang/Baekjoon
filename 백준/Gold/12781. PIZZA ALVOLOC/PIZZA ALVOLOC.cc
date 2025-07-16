#include <iostream>

using namespace std;

struct Point {
	int x, y;
};

int CCW(Point a, Point b, Point c) {
	int ans = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (ans > 0) {
		return 1;
	}
	if (ans < 0) {
		return -1;
	}
	if (ans == 0) {
		return 0;
	}
}

int main() {
	Point a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

	int r1 = CCW(a, b, c);
	int r2 = CCW(a, b, d);
	if (r1 * r2 < 0) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}