#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(string a, string b) {

	int aSum = 0;
	int bSum = 0;

	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	
	for (int i = 0; i < a.length(); i++) {
		if (isdigit(a[i])) {
			aSum += a[i] - '0';
		}
		if (isdigit(b[i])) {
			bSum += b[i] - '0';
		}
	}

	if (aSum != bSum) {
		return aSum < bSum;
	}
	else {
		return a < b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	vector<string> v;
	string str;

	cin >> n;

	while (n--) {
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}