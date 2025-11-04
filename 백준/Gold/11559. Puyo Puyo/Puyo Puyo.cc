#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[12][6];
bool visited[12][6];
bool boom;
int ans = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    queue<pair<int, int>> crush;

    int cnt = 1;
    q.push({ x, y });
    crush.push({ x, y });
    visited[x][y] = true;

    while (!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
            if (visited[nx][ny]) continue;
            if (map[xx][yy] != map[nx][ny]) continue;
            visited[nx][ny] = true;

            q.push({ nx, ny });
            crush.push({ nx, ny });
            cnt++;
        }
    }

    if (cnt >= 4) {
        boom = true;
        while (!crush.empty()) {
            map[crush.front().first][crush.front().second] = '.';
            crush.pop();
        }
    }
}

int main() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> map[i][j];
        }
    }

    while (true) {
        boom = false;
        memset(visited, 0, sizeof(visited));

        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] != '.' && !visited[i][j]) {
                    BFS(i, j);
                }
            }
        }

        if (!boom) break;
        ans++;

        for (int i = 0; i < 6; i++) {
            queue<char> qu;
            for (int j = 11; j >= 0; j--) {
                if (map[j][i] != '.') {
                    qu.push(map[j][i]);
                    map[j][i] = '.';
                }
            }
            int standard = 11;
            while (!qu.empty()) {
                map[standard][i] = qu.front();
                qu.pop();
                standard--;
            }
        }
    }

    cout << ans;
}
