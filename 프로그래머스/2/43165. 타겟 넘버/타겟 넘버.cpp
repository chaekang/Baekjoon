#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[2] = { 1, -1 };

int DFS(int index, int sum, vector<int> &numbers, int target) {
    if (index == numbers.size()) {
        if (sum == target) {
            return 1;
        }
        return 0;
    }
    
    int cnt = 0;
    int x = numbers[index];
    for (int i=0; i<2; i++) {
        int nsum = sum + x * dx[i];

        cnt += DFS(index+1, nsum, numbers, target);
    }
    
    return cnt;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = DFS(0, 0, numbers, target);
    
    return answer;
}