#include <iostream>
#include <vector>

using namespace std;

int n, ans = 100000000;
vector<int> sour;
vector<int> bitter;

void cook(int idx, int cnt, int s, int b) {
	if (idx == n) {
		if (cnt > 0) {
			ans = min(ans, abs(s - b));
		}
		return;
	}

	cook(idx + 1, cnt, s, b);
	cook(idx + 1, cnt + 1, s * sour[idx], b + bitter[idx]);
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	sour.resize(n);
	bitter.resize(n);

	for (int i = 0; i < n; i++) {
		int s, b;
		cin >> s >> b;
		sour[i] = s;
		bitter[i] = b;
	}

	cook(0, 0, 1, 0);

	cout << ans;
}