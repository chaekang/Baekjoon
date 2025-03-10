#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int w, h;
	int p, q;
	int t;
	int x, y;

	cin >> w >> h;
	cin >> p >> q;
	cin >> t;
	
	if (((p + t) / w) % 2 == 0) {
		x = (p + t) % w;
	}
	else {
		x = w - (p + t) % w;
	}

	if (((q + t) / h) % 2 == 0) {
		y = (q + t) % h;
	}
	else {
		y = h - (q + t) % h;
	}

	cout << x << " " << y;
}