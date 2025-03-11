#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> arr, tree;

// 세그먼트 트리 초기화
ll init(int node, int start, int end) {
    if (start == end) 
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

// 구간 합 구하기
ll sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) // 범위를 벗어난 경우
        return 0;
    if (left <= start && end <= right) // 범위 안에 완전히 포함된 경우
        return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

// 값 업데이트
void update(int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) // 범위를 벗어난 경우
        return;
    tree[node] += diff;
    if (start != end) { // 리프 노드가 아닐 경우
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    arr.resize(n + 1);
    tree.resize(4 * n);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // 세그먼트 트리 초기화
    init(1, 1, n);

    for (int i = 0; i < m + k; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        if (a == 1) { // b번째 수를 c로 변경
            ll diff = c - arr[b];
            arr[b] = c;
            update(1, 1, n, b, diff);
        } else if (a == 2) { // b부터 c까지 합 구하기
            cout << sum(1, 1, n, b, c) << "\n";
        }
    }
    return 0;
}
