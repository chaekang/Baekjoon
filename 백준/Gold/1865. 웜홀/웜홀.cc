#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to, cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--) {
        int n, m, w;
        cin >> n >> m >> w;

        vector<Edge> edges;
        int dist[501];

        for (int i = 1; i <= n; i++) {
            dist[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            edges.push_back({ from, to, cost });
            edges.push_back({ to, from, cost });
        }

        for (int i = 0; i < w; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            edges.push_back({ from, to, -cost });
        }

        for (int i = 1; i <= n - 1; i++) {
            for (auto& e : edges) {
                if (dist[e.from] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[e.from] + e.cost;
                }
            }
        }

        bool hasNegativeCycle = false;
        for (auto& e : edges) {
            if (dist[e.from] + e.cost < dist[e.to]) {
                hasNegativeCycle = true;
                break;
            }
        }

        if (hasNegativeCycle)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
