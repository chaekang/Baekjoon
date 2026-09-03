#include <string>
#include <vector>
#include <queue>

using namespace std;

int BFS(int xx, vector<vector<int>> &graph, vector<bool> &visited) {
    queue<int> q;
    q.push(xx);
    visited[xx] = true;
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        for (int i=0; i<graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
            }
        }
    }
    
    return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if(computers[i][j] == 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            answer += BFS(i, graph, visited);
        }
    }
    
    return answer;
}