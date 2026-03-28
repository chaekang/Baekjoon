#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int m;
        cin >> m;

        vector<int> dp(m + 1, 0);
        dp[0] = 1;

        for (int a : arr) {
            for (int i = a; i <= m; i++) {
                dp[i] += dp[i - a];
            }
        }

        cout << dp[m] << '\n';
    }

    return 0;
}