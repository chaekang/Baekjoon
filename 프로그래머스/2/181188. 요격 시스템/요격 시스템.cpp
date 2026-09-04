#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), []
        (const vector<int> &a, const vector<int> &b) {
           return a[1] < b[1]; 
        });
    
    int end = 0;
    
    for (int i=0; i< targets.size(); i++) {
        if (targets[i][0] >= end) {
            answer++;
            end = targets[i][1];
        }
    }
    
    return answer;
}