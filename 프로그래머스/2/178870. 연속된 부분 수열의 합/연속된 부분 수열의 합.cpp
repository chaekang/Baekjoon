#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int sum = 0;
    int left = 0;
    
    for (int right = 0; right < sequence.size(); right++) {
        sum += sequence[right];
        
        while (sum > k && left <= right) {
            sum -= sequence[left];
            left++;
        }
        
        if (sum == k) {
            if (answer.empty()) {
                answer = {left, right};
            }
            else {
                if (answer[1] - answer[0] > right - left) {
                    answer = {left, right};
                }
            }
        }
    }
    
    return answer;
}