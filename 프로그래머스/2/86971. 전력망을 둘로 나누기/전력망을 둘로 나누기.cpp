#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector<vector<int>> &v, vector<bool> &visited, int x) {
    queue<int> q;
    q.push(x);
    visited[x] = true;
    int cnt = 1;
    
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        cnt++;
        
        for (int i=0; i<v[y].size(); i++) {
            if (!visited[v[y][i]]) {
                q.push(v[y][i]);
                visited[v[y][i]] = true;
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100000000000;
    
    for (int i = 0; i < wires.size(); i++) {
        vector<vector<int>> tmp = wires;
        tmp.erase(tmp.begin() + i);
        
        vector<vector<int>> graph(n+1);
        for (int j=0; j<tmp.size(); j++) {
            int a = tmp[j][0];
            int b = tmp[j][1];
            
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<bool> visited(n+1, false);
        vector<int> ans;
        
        for (int j =1; j<=n; j++) {
            if (!visited[j]) {
                int cnt = BFS(graph, visited, j);
                ans.push_back(cnt);
            }
        }
        
        if (answer > abs(ans[0]-ans[1])) {
            answer = abs(ans[0]-ans[1]);
        }
    }
    
    return answer;
}