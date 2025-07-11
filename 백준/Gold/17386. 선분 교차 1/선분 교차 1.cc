#include <iostream>

using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	long long op = 1LL * (b.first - a.first) * (c.second - a.second)
		- 1LL * (b.second - a.second) * (c.first - a.first);
	if (op > 0) return 1; 
	if (op < 0) return -1;
	return 0; 
}

int main() {
	pair<int, int> a, b, c, d;
	cin >> a.first >> a.second >> b.first >> b.second;
	cin >> c.first >> c.second >> d.first >> d.second;

	int ab_c = ccw(a, b, c);
	int ab_d = ccw(a, b, d);
	int cd_a = ccw(c, d, a);
	int cd_b = ccw(c, d, b);

	if (ab_c * ab_d < 0 && cd_a * cd_b < 0)
		cout << 1;
	else
		cout << 0;
}