#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> crane(n);
    for (int i = 0; i < n; i++) cin >> crane[i];
    sort(crane.begin(), crane.end(), greater<int>());

    int m;
    cin >> m;

    vector<int> box(m);
    for (int i = 0; i < m; i++) cin >> box[i];
    sort(box.begin(), box.end(), greater<int>());

    if (crane[0] < box[0]) {
        cout << -1;
        return 0;
    }

    vector<int> pos(n, 0);
    vector<bool> moved(m, false);
    int movedCount = 0;
    int ans = 0;

    while (movedCount < m) {
        ans++;
        for (int i = 0; i < n; i++) {
            while (pos[i] < m) {
                if (!moved[pos[i]] && crane[i] >= box[pos[i]]) {
                    moved[pos[i]] = true;
                    movedCount++;
                    pos[i]++;
                    break;
                }
                pos[i]++;
            }
        }
    }

    cout << ans;
}
