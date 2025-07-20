#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int w, h, x, y, p;
	cin >> w >> h >> x >> y >> p;

	int ans = 0;
	for (int i = 0; i < p; i++) {
		double px, py;
		cin >> px >> py;

		double leftCircle = sqrt(pow(x - px, 2) + pow(y + h / 2 - py, 2));
		double rightCircle = sqrt(pow(x + w - px, 2) + pow(y + h / 2 - py, 2));

		if ((px >= x && px <= x + w) && (py >= y && py <= y + h)) {
			ans++;
		}
		else if (leftCircle <= h / 2) {
			ans++;
		}
		else if (rightCircle <= h / 2) {
			ans++;
		}
	}
	cout << ans;
}