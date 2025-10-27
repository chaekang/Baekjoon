#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n), d(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<int> ab, cd;
    ab.reserve(n * n);
    cd.reserve(n * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    int start = 0;
    int end = n * n - 1;
    long long ans = 0;

    while (start < n * n && end >= 0) {
        long long sum = (long long)ab[start] + cd[end];
        if (sum < 0) start++;
        else if (sum > 0) end--;
        else {
            long long ab_val = ab[start];
            long long cd_val = cd[end];
            long long cnt_ab = 0, cnt_cd = 0;
            while (start < n * n && ab[start] == ab_val) {
                cnt_ab++;
                start++;
            }
            while (end >= 0 && cd[end] == cd_val) {
                cnt_cd++;
                end--;
            }
            ans += cnt_ab * cnt_cd;
        }
    }

    cout << ans;
}
