#include <iostream>
#include <cmath>

using namespace std;

double pi = 3.14159265358979323846;

double x1, Y1, r1, x2, y2, r2;
double dist;

double noOverlap() {
	return 0;
}

double Overlap() {
	if (r1 < r2) {
		return r1 * r1 * pi;
	}
	else {
		return r2 * r2 * pi;
	}
}

double Contact() {
	double theta1 = acos((r1 * r1 + dist * dist - r2 * r2) / (2 * r1 * dist));
	double theta2 = acos((r2 * r2 + dist * dist - r1 * r1) / (2 * r2 * dist));

	theta1 = theta1 * 2;
	theta2 = theta2 * 2;

	double S1 = (r1 * r1 * theta1 * 0.5) - (r1 * r1 * sin(theta1) * 0.5);
	double S2 = (r2 * r2 * theta2 * 0.5) - (r2 * r2 * sin(theta2) * 0.5);

	return S1 + S2;
}

int main() {
	cin >> x1 >> Y1 >> r1 >> x2 >> y2 >> r2;
	dist = sqrt((x1 - x2) * (x1 - x2) + (Y1 - y2) * (Y1 - y2));

	double ans = 0;
	if (r1 + r2 < dist) {
		ans = noOverlap();
	}
	else if (abs(r2 - r1) >= dist) {
		ans = Overlap();
	}
	else {
		ans = Contact();
	}

	cout << fixed;
	cout.precision(3);
	cout << ans;
}