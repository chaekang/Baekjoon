#include <iostream>
#include <algorithm>

using namespace std;

int tree[1001];
int dp[3][1001][32];

int main()
{
	int t, w;
	cin >> t >> w;
	for (int i = 1; i <= t; i++)
	{
		cin >> tree[i];
	}

    if (tree[1] == 1) {
        dp[1][1][1] = 1;
    }
    else {
        dp[2][1][2] = 1;
    }
    for (int i = 2; i <= t; ++i) {
        for (int mv = 1; mv <= w + 1; ++mv) {
            if (tree[i] == 1) {
                dp[1][i][mv] = max(dp[1][i - 1][mv], dp[2][i - 1][mv - 1]) + 1;
                dp[2][i][mv] = max(dp[1][i - 1][mv - 1], dp[2][i - 1][mv]);
            }
            else {
                dp[1][i][mv] = max(dp[1][i - 1][mv], dp[2][i - 1][mv - 1]);
                dp[2][i][mv] = max(dp[1][i - 1][mv - 1], dp[2][i - 1][mv]) + 1;
            }
        }
    }

    int res = -1;
    for (int i = 1; i <= w + 1; ++i) {
        res = max({ res, dp[1][t][i], dp[2][t][i] });
    }
    cout << res;
}