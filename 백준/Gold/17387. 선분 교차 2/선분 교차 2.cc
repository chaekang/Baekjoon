#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
	long long x, y;
};

int CCW(Point a, Point b, Point c) {
	long long cross = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	if (cross > 0) return 1;
	else if (cross < 0) return -1;
	else return 0;
}

bool inRange(Point a, Point b, Point c) {
	if (a.x > b.x) swap(a, b);
	if (a.y > b.y) swap(a.y, b.y);
	return a.x <= c.x && c.x <= b.x && a.y <= c.y && c.y <= b.y;
}

bool isOverlap(Point a, Point b, Point c, Point d) {
	if (a.x > b.x || (a.x == b.x && a.y > b.y)) swap(a, b);
	if (c.x > d.x || (c.x == d.x && c.y > d.y)) swap(c, d);
	if (a.x == b.x && c.x == d.x && a.x == c.x) {
		return max(a.y, c.y) <= min(b.y, d.y);
	}
	return max(a.x, c.x) <= min(b.x, d.x);
}

int main() {
	Point a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

	int ab_c = CCW(a, b, c);
	int ab_d = CCW(a, b, d);
	int cd_a = CCW(c, d, a);
	int cd_b = CCW(c, d, b);

	if (ab_c * ab_d < 0 && cd_a * cd_b < 0) {
		cout << 1;
	}
	else if (ab_c * ab_d == 0 && cd_a * cd_b == 0) {
		if (isOverlap(a, b, c, d)) cout << 1;
		else cout << 0;
	}
	else {
		if (ab_c == 0 && inRange(a, b, c)) cout << 1;
		else if (ab_d == 0 && inRange(a, b, d)) cout << 1;
		else if (cd_a == 0 && inRange(c, d, a)) cout << 1;
		else if (cd_b == 0 && inRange(c, d, b)) cout << 1;
		else cout << 0;
	}
}
