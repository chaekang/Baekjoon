#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long double ld;

struct Point {
	ld x, y;
};

ld CCW(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

ld Dist(Point a, Point b) {
	ld x = a.x - b.x;
	ld y = a.y - b.y;
	return sqrt(x * x + y * y);
}

ld Circum(ld x, ld y) {
	return 2 * (x + y);
}

int main() {
	cout.precision(14);
	cout << fixed;

	Point a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

	if (CCW(a, b, c) == 0) {
		cout << -1;
	}
	else {
		ld ab = Dist(a, b);
		ld bc = Dist(b, c);
		ld ca = Dist(c, a);

		vector<ld> v;
		v.push_back(Circum(ab, bc));
		v.push_back(Circum(bc, ca));
		v.push_back(Circum(ca, ab));

		ld minC = 999999;
		ld maxC = -999999;

		for (auto i : v) {
			if (i > maxC) {
				maxC = i;
			}
			if (i < minC) {
				minC = i;
			}
		}

		cout << maxC - minC;
	}
}