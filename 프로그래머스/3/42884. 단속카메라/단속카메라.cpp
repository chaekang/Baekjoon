#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(),
        [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
    
    int cam = -300001;
    
    for (int i=0; i<routes.size(); i++) {
        if (routes[i][0] > cam) {
            cam = routes[i][1];
            answer++;
        }
    }
    
    return answer;
}