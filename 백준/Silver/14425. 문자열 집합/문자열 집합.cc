#include <iostream>
#include <unordered_set>
#include <cstring>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	unordered_set<string> s;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		s.insert(x);
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		string x;
		cin >> x;
		if (s.count(x)) {
			ans++;
		}
	}
	cout << ans;
}