#include <iostream>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;

            q.push({ j, x });
            pq.push(x);
        }

        int ans = 0;
        while (!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();

            if (pq.top() == value) {
                pq.pop();

                ans++;

                if (index == m) {
                    cout << ans << endl;
                    break;
                }
            }
            else q.push({ index,value });
        }
    }
}