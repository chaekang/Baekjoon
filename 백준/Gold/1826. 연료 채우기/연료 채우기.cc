#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> stations(n);
    for (int i = 0; i < n; i++) {
        cin >> stations[i].first >> stations[i].second;
    }

    int l, p;
    cin >> l >> p;

    sort(stations.begin(), stations.end());

    stations.push_back({ l, 0 });

    priority_queue<int> pq;
    int ans = 0;
    int prev = 0;

    for (auto& s : stations) {
        int dist = s.first - prev;
        p -= dist;
        prev = s.first;

        while (p < 0 && !pq.empty()) {
            p += pq.top();
            pq.pop();
            ans++;
        }

        if (p < 0) {
            cout << -1;
            return 0;
        }

        pq.push(s.second);
    }

    cout << ans;
}
