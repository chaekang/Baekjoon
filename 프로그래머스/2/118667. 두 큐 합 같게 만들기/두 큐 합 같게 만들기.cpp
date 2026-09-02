#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1;
    queue<int> q2;
    long long targetSum = 0;
    
    for (int i=0; i<queue1.size(); i++) {
        int a = queue1[i];
        q1.push(a);
        
        int b = queue2[i];
        q2.push(b);
        
        targetSum += a + b;
    }
    
    if (targetSum % 2 != 0) {
        return -1;
    }
    
    targetSum /= 2;
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    
    int limit = q1.size() * 4;
    
    while (answer < limit) {
        if (sum1 == targetSum) {
            break;
        }
        
        if (sum1 > targetSum) {
            answer++;
            int a = q1.front();
            q1.pop();
            q2.push(a);
            sum1 -= a;
            sum2 += a;
        }
        else {
            answer++;
            int a = q2.front();
            q2.pop();
            q1.push(a);
            sum2 -= a;
            sum1 += a;
        }
    }
    
    if (sum1 != targetSum) {
        answer = -1;
    }
    
    return answer;
}