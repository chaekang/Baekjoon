#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int size = brown + yellow;
    for (int i=3; i*i<=size; i++) {
        if (size % i == 0) {
            int j = size / i;
            if ((i-2)*(j-2) == yellow) {
                answer.push_back(j);
                answer.push_back(i);
                break;
            }
        }
    }
    
    return answer;
}