#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 1234;

    vector<vector<int>> dp(board.size(), vector<int>(board[0].size()));
    int maxSize = 0;
    
    for (int i=0; i<board[0].size(); i++) {
        dp[0][i] = board[0][i];
        maxSize = max(maxSize, dp[0][i]);
    }
    
    for (int i=0; i<board.size(); i++) {
        dp[i][0] = board[i][0];
        maxSize = max(maxSize, dp[i][0]);
    }
    
    
    for (int i=1; i<board.size(); i++) {
        for (int j=1; j<board[0].size(); j++) {
            if (board[i][j] == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
            maxSize = max(dp[i][j], maxSize);
        }
    }

    answer = maxSize * maxSize;
    
    return answer;
}