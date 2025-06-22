#include <iostream>
#include <queue>

using namespace std;
#define MAX 100001

int n, k;
bool visited[MAX];

int HideAndSeek() {
	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visited[n] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == k) {
			return cnt;
		}

		// 순간이동 (우선적으로 탐색해야 더 빠름)
		if (x * 2 < MAX && !visited[x * 2]) {
			q.push({ x * 2, cnt });
			visited[x * 2] = true;
		}
		if (x - 1 >= 0 && !visited[x - 1]) {
			q.push({ x - 1, cnt + 1 });
			visited[x - 1] = true;
		}
		if (x + 1 < MAX && !visited[x + 1]) {
			q.push({ x + 1, cnt + 1 });
			visited[x + 1] = true;
		}
	}
	return -1;
}

int main() {
	cin >> n >> k;
	cout << HideAndSeek();
}
