#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    
    do {
        int cur = k;
        int ans = 0;
        for (int i=0; i<dungeons.size(); i++) {
            int need = dungeons[i][0];
            int use = dungeons[i][1];
            
            if (need > cur) {
                break;
            }
            else {
                cur -= use;
                ans++;
            }
        }
        
        if (ans > answer) {
            answer = ans;
        }
    }
    while (next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}