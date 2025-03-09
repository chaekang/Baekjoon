#include <iostream>
#include <queue>

using namespace std;

int n;

int graph[20][20];
bool visited[20][20];
queue<pair<pair<int, int>, int>> q;

int nx[] = { 0, -1, 0, 1 };
int ny[] = { -1, 0, 1, 0 };
int curX, curY;

int result = 0;
int count = 0;
int sharkSize = 2;

bool BFS(int xx, int yy) {
    fill(&visited[0][0], &visited[0][0] + 20 * 20, false); // 방문 배열 초기화
    q = queue<pair<pair<int, int>, int>>(); // 큐 초기화

    q.push({ {xx, yy}, 0 });
    visited[yy][xx] = true;

    int temp = -1;    // 이전에 발견한 물고기까지의 거리
    bool eat = false;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;  
        q.pop();

        // 먹을 수 있는 물고기 발견
        if (graph[y][x] > 0 && graph[y][x] < sharkSize) {
            if (!eat || cnt < temp || (cnt == temp && (y < curY || (y == curY && x < curX)))) {
                eat = true;
                temp = cnt;
                curX = x;
                curY = y;
            }
        }

        // 네 방향 탐색
        for (int i = 0; i < 4; i++) {
            int dx = x + nx[i];
            int dy = y + ny[i];

            if (dx >= 0 && dy >= 0 && dx < n && dy < n && !visited[dy][dx] && graph[dy][dx] <= sharkSize) {
                q.push({ {dx, dy}, cnt + 1 });
                visited[dy][dx] = true;
            }
        }
    }

    if (eat) {
        graph[curY][curX] = 0;
        result += temp;
        count++;
        if (count == sharkSize) {
            sharkSize++;
            count = 0;
        }
        return true; // 물고기를 먹었음
    }
    return false; // 먹을 물고기 없음 -> 종료
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 9) {
                curX = j;
                curY = i;
                graph[i][j] = 0;
            }
        }
    }

    // 물고기가 없을 때까지 반복
    while (BFS(curX, curY));

    cout << result << '\n';
    return 0;
}
