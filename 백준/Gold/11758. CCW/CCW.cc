#include <iostream>

using namespace std;

int main() {
	pair<int, int> dots[3];
	for (int i = 0; i < 3; i++) {
		cin >> dots[i].first >> dots[i].second;
	}

	int ax = dots[1].first - dots[0].first;
	int ay = dots[1].second - dots[0].second;

	int bx = dots[2].first - dots[1].first;
	int by = dots[2].second - dots[1].second;

	int cross = ax * by - bx * ay;

	if (cross == 0) {
		cout << 0;
	}
	else if (cross > 0) {
		cout << 1;
	}
	else {
		cout << -1;
	}
}