#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int index;
    int dist;
};

vector<Node> tree[100001]; // 충분한 범위 확보
bool visited[100001];
int maxDist = 0;
int maxNode;

void DFS(int node, int dist) {
    visited[node] = true;

    if (dist > maxDist) {
        maxDist = dist;
        maxNode = node;
    }

    for (auto& next : tree[node]) {
        if (!visited[next.index]) {
            DFS(next.index, dist + next.dist);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v;
    cin >> v;

    for (int i = 0; i < v; ++i) {
        int node;
        cin >> node;

        while (true) {
            int x, y;
            cin >> x;
            if (x == -1) break;
            cin >> y;
            tree[node].push_back({ x, y });
        }
    }

    fill(visited, visited + v + 1, false);
    DFS(1, 0); // 임의의 시작 노드 (1)

    fill(visited, visited + v + 1, false);
    maxDist = 0;
    DFS(maxNode, 0);

    cout << maxDist << '\n';

    return 0;
}
