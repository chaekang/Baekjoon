#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
bool visited[1000001];

int bfs() {
    queue<pair<int, int>> q; // {현재 층, 버튼 누른 횟수}
    q.push({ s, 0 });
    visited[s] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == g) return cnt;

        if (cur + u <= f && !visited[cur + u]) {
            visited[cur + u] = true;
            q.push({ cur + u, cnt + 1 });
        }

        if (cur - d > 0 && !visited[cur - d]) {
            visited[cur - d] = true;
            q.push({ cur - d, cnt + 1 });
        }
    }

    return -1; // 못 간 경우
}

int main() {
    cin >> f >> s >> g >> u >> d;

    int result = bfs();

    if (result == -1)
        cout << "use the stairs\n";
    else
        cout << result << '\n';

    return 0;
}
