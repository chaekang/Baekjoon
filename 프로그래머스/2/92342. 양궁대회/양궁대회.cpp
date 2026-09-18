#include <string>
#include <vector>

using namespace std;

vector<int> cur(11, 0);
vector<int> ans(11, 0);
int maxDiff = 0;

void DFS(int index, int remain, vector<int> &info) {
    if (index == 11) {
        cur[10] += remain;
        
        int apeach = 0;
        int lion = 0;
        for (int i = 0; i < 11; i++) {
            int score = 10 - i;

            if (cur[i] > info[i]) {
                lion += score;
            }
            else if (info[i] > 0) {
                apeach += score;
            }
        }
        int diff = lion - apeach;
        
        if (diff > 0) {
            if (maxDiff < diff) {
                maxDiff = diff;
                ans = cur;
            }
            else if (maxDiff == diff) {
                for (int i = 10; i>= 0; i--) {
                    if (cur[i] > ans[i]) {
                        ans = cur;
                        break;
                    }

                    if (cur[i] < ans[i]) {
                        break;
                    }
                }
            }
        }
        
        cur[10] -= remain;
        return;
    }
    
    int need = info[index] + 1;
    
    if (remain >= need) {
        cur[index] = need;
        DFS(index+1, remain - need, info);
        cur[index] = 0;
    }
    
    DFS(index+1, remain, info);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    DFS(0, n, info);
    if (ans == vector<int>(11, 0)) {
        ans = { -1 };
    }
    
    answer = ans;
    return answer;
}