#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	long long q;

	cin >> n;

	q = sqrt(n);

	if (pow(q, 2) < n) {
		q++;
	}

	cout << q;
}