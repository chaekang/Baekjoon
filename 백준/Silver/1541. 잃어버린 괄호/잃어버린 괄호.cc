#include <iostream>
#include <string>

using namespace std;

int main() {
	string formula;
	cin >> formula;

	bool isMinus = false;
	string num;
	int ans = 0;

	for (int i = 0; i <= formula.size(); i++) {
		if (formula[i] == '+' || formula[i] == '-' || i == formula.size()) {
			if (isMinus) {
				ans -= stoi(num);
				num = "";
			}
			else {
				ans += stoi(num);
				num = "";
			}
		}
		else {
			num += formula[i];
		}

		if (formula[i] == '-') {
			isMinus = true;
		}
	}

	cout << ans;
}