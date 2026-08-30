#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for (int i=0; i< priorities.size(); i++) {
        q.push(pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    while (true) {
        int index = q.front().first;
        int priority = q.front().second;
        
        q.pop();
        
        if (priority < pq.top()) {
            q.push(pair(index, priority));
            continue;
        }
        
        pq.pop();
        answer++;
        
        if (index == location) {
            break;
        }
    }
    
    return answer;
}