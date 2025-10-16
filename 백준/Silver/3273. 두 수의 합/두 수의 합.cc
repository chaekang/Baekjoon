#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
    int x;
    cin >> x;

	sort(v.begin(), v.end());

    int cnt = 0, sum = 0, lo = 0, hi = n - 1;
    while (lo < hi) {
        sum = v[lo] + v[hi];
        if (sum > x) hi--;
        else if (sum < x) lo++;
        else {
            cnt++;
            hi--;
            lo++;
        }
    }
    cout << cnt;
}