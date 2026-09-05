#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    
    for (int i=0; i<money.size(); i++) {
        int target = money[i];
        
        for (int j=target; j<=n; j++) {
            dp[j] += dp[j-target];
        }
    }
    
    answer = dp[n];
    return answer;
}