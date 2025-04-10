#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int n;
	vector<int> num;
	cin >> n;
	num.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());

	// 산술평균
	int arith = 0;
	for (int i = 0; i < n; i++) {
		arith += num[i];
	}
	arith = round((double)arith / n);

	// 중앙값
	int mid = num[n / 2];

	// 최빈값
	map<int, int> freq;
	int maxFreq = 0;
	for (int val : num) {
		freq[val]++;
		maxFreq = max(maxFreq, freq[val]);
	}

	vector<int> modes;
	for (auto& p : freq) {
		if (p.second == maxFreq) {
			modes.push_back(p.first);
		}
	}

	int modeNum;
	if (modes.size() == 1) {
		modeNum = modes[0];
	}
	else {
		modeNum = modes[1];
	}

	// 범위
	int range = num.back() - num.front();

	cout << arith << "\n" << mid << "\n" << modeNum << "\n" << range;
}