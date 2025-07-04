#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		long long x, y;
		cin >> x >> y;
		long long dist = y - x;
		long long max = 0;

		while (max * max <= dist) {
			max++;
		}
		max--;
		long long move = 2 * max - 1;
		long long rem = y - x - max * max;
		rem = (long long)ceil((double)rem / (double)max);
		move += rem;
		
		cout << move << "\n";
	}
}