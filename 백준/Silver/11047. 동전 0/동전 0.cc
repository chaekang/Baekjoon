#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 내림차순 정렬
    sort(arr.begin(), arr.end(), greater<int>());

    int count = 0;

    for (int i = 0; i < n; i++) {
        int used = k / arr[i];
        count += used;
        k %= arr[i];
    }

    cout << count;
    return 0;
}