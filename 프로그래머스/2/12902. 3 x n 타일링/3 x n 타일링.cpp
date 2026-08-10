#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int solution(int n) {
    if (n % 2 != 0) {
        return 0;
    }
    
    vector<long long> dp(n+1, 0);
    dp[0] = 1;
    dp[2] = 3;
    
    for (int i=4; i<= n; i+=2) {
        dp[i] = (4 * dp[i-2] - dp[i-4] + MOD) % MOD;
    }
    
    return dp[n];
}