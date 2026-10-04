#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<vector<bool>> visited;

int BFS(int xx, int yy, const vector<string> &maps) {
    queue<pair<int, int>> q;
    
    visited[xx][yy] = true;
    q.push({xx, yy});
    
    int ans = maps[xx][yy] - '0';
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size() || maps[nx][ny] == 'X' || visited[nx][ny]) {
                continue;
            }
            
            ans += maps[nx][ny] - '0';
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    
    return ans;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    visited.resize(maps.size(), vector<bool>(maps[0].size(), false));
    
    for (int i=0; i<maps.size(); i++) {
        for (int j=0; j<maps[0].size(); j++) {
            if (visited[i][j] || maps[i][j] == 'X') {
                continue;
            }
            
            int tmp = BFS(i, j, maps);
            answer.push_back(tmp);
        }
    }
    
    if (answer.empty()) {
        answer.push_back(-1);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}