#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    for (int h = 1; h <= citations[citations.size()-1]; h++) {
        int count = citations.end() - lower_bound(citations.begin(), citations.end(), h);
        if (count > h) {
            answer = h;
        }
        else if (count < h) {
            break;
        }
        else {
            answer = h;
            break;
        }
    }
    
    return answer;
}