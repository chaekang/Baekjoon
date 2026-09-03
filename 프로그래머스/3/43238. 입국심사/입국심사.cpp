#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long left = 0;
    long long maxTime = *max_element(times.begin(), times.end());
    long long right = maxTime * n;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        
        for (int i=0; i<times.size(); i++) {
            cnt += mid / times[i];
        }
        
        if (cnt >= n) {
            right = mid-1;
        }
        else {
            left = mid+1;
        }
    }
    
    answer = left;
    
    return answer;
}