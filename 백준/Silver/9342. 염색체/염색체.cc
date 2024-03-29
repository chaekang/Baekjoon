#include <iostream>
#include <regex>

using namespace std;

bool RegularExpression(const string& str);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	string str;
	cin >> t;

	while (t--) {
		cin >> str;
		if (RegularExpression(str)) {
			cout << "Infected!" << "\n";
		}
		else {
			cout << "Good" << "\n";
		}
	}
}

bool RegularExpression(const string& str) {
	regex r("^[ABCDEF]?A+F+C+[ABCDEF]?$");
	return regex_match(str, r);
}