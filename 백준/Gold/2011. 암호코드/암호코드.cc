#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dp[5001];

int main() {
	string s;
	cin >> s;

    if (s[0] == '0') {
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= s.size(); i++) {
        if (s[i - 1] != '0') {
            dp[i] = dp[i - 1];
        }

        int tmp = stoi(s.substr(i - 2, 2));
        if (tmp >= 10 && tmp <= 26) {
            dp[i] = (dp[i] + dp[i - 2]) % 1000000;
        }
    }

    cout << dp[s.size()] % 1000000;
}