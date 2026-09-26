#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int BFS(int xx, int yy, char target, vector<string> &maps) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(maps.size(), vector<int>(maps[0].size(), -1));
    
    q.push({xx, yy});
    dist[xx][yy] = 0;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (maps[x][y] == target) {
            return dist[x][y];
        }
        
        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= maps.size() || 
                ny >= maps[0].size() || maps[nx][ny] == 'X') {
                continue;
            }
            
            if (dist[nx][ny] == -1) {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    int x = 0;
    int y = 0;
    
    for (int i=0; i<maps.size(); i++) {
        for (int j = 0; j<maps[0].size(); j++) {
            if (maps[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }
    
    int tmp = BFS(x, y, 'L', maps);
    if (tmp == -1) {
        return -1;
    }
    
    for (int i=0; i<maps.size(); i++) {
        for (int j = 0; j<maps[0].size(); j++) {
            if (maps[i][j] == 'L') {
                x = i;
                y = j;
            }
        }
    }
    
    int tmp1 = BFS(x, y, 'E', maps);
    if (tmp1 == -1) {
        return -1;
    }
    answer = tmp + tmp1;
    
    return answer;
}