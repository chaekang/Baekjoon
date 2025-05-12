#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s = "";
	string rev = "";
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		s += c;
		rev += char(((c - '0' + 1) % 4 + 1) + '0');
	}
	reverse(rev.begin(), rev.end());

	int k;
	cin >> k;
	vector<string> result;

	for (int i = 0; i < k; i++) {
		string input = "";
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			input += c;
		}

		string temp = input;
		for (int j = 0; j < n; j++) {
			if (temp == s || temp == rev) {
				result.push_back(input);
				break;
			}
			temp = temp.substr(1) + temp[0];
		}
	}

	cout << result.size() << "\n";
	for (const auto& str : result) {
		for (int i = 0; i < str.size(); ++i) {
			cout << str[i];
			if (i < str.size() - 1) cout << " ";
		}
		cout << "\n";
	}
}
