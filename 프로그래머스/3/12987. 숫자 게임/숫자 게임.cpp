#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = -1;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int tmp = 0;
    for (int i=0; i<A.size(); i++) {
        if (answer > tmp) {
            break;
        }
        
        tmp = 0;
        for (int j=0; j<A.size(); j++) {
            if (A[j] < B[j]) {
                tmp++;
            }
        }
        
        if (tmp > answer) {
            answer = tmp;
        }
        
        int top = B[0];
        B.erase(B.begin());
        B.push_back(top);
    }
    
    return answer;
}