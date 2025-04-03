#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int n;
	vector<ll> cards;
	int m;
	vector<ll> number;
	vector<int> ans;

	cin >> n;
	cards.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	cin >> m;
	number.resize(m);
	ans.resize(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> number[i];
	}

	sort(cards.begin(), cards.end());

	for (int i = 0; i < m; i++) {
		int start = 0;
		int end = n - 1;

		while (start <= end) {
			ll mid = (start + end) / 2;

			if (number[i] > cards[mid]) {
				start = mid + 1;
			}
			else if (number[i] < cards[mid]) {
				end = mid - 1;
			}
			else {
				ans[i] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}
}