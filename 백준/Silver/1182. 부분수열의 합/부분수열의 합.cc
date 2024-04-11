#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int n, s;
int cnt = 0;

void Subsequence(int idx, int tmp) {

	if (idx == n) {
		return;
	}
	if (tmp + arr[idx] == s) {
		cnt++;
	}
	Subsequence(idx + 1, tmp);
	Subsequence(idx + 1, tmp + arr[idx]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	Subsequence(0, 0);
	cout << cnt;
}