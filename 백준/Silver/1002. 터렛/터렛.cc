#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> result;

void ContractPoint(int a, int b, int x, int y, int p, int q) {
	double dist = sqrt(pow(a - b, 2) + pow(x - y, 2));
	int sum = p + q;
	int diff = abs(p - q);

	if (dist == 0) {
		if (p == q) {
			result.push_back(-1);
		}
		else {
			result.push_back(0);
		}
	}
	else if (dist == sum || dist == diff) {
		result.push_back(1);
	}
	else if (dist < sum && dist > diff) {
		result.push_back(2);
	}
	else {
		result.push_back(0);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	int a, x, p, b, y, q;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> x >> p >> b >> y >> q;
		ContractPoint(a, b, x, y, p, q);
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}