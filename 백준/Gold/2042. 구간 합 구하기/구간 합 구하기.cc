#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m, k;
vector<ll> arr;
vector<ll> tree;

ll Init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[node] = Init(node * 2, start, mid) + Init(node * 2 + 1, mid + 1, end);
}

ll Sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && right >= end) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	return Sum(node * 2, start, mid, left, right) + Sum(node * 2 + 1, mid + 1, end, left, right);
}

void Update(int node, int start, int end, int index, ll diff) {
	if (index > end || index < start) {
		return ;
	}
	tree[node] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		Update(node * 2, start, mid, index, diff);
		Update(node * 2 + 1, mid + 1, end, index, diff);
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

	Init(1, 1, n);

	for (int i = 0; i < m + k; i++) {
		int a, b;
		ll c;

		cin >> a >> b >> c;

		if (a == 1) {
			ll diff = c - arr[b];
			arr[b] = c;
			Update(1, 1, n, b, diff);
		}
		else if (a == 2) {
			cout << Sum(1, 1, n, b, c) << "\n";
		}
	}
}