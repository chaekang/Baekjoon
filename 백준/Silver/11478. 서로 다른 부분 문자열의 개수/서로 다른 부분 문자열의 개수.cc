#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	string x;
	cin >> x;
	set<string> s;

	int len = x.length();
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			s.insert(x.substr(i, j - i + 1));
		}
	}

	cout << s.size();
}