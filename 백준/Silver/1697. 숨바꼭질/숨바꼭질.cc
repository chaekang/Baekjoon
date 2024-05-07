#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 100000

queue<pair<int, int>> q;
bool visited[100001];
int n, k;

void BFS(int x) {
	q.push(make_pair(x, 0));

	while (!q.empty()) {
		int loc = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (loc == k) {
			cout << cnt;
			break;
		}

		if (0 <= (loc + 1) && (loc + 1) <= MAX_SIZE) {
			if (!visited[loc + 1]) {
				visited[loc + 1] = true;
				q.push(make_pair(loc + 1, cnt + 1));
			}
		}
		if (0 <= (loc - 1) && (loc - 1) <= MAX_SIZE) {
			if (!visited[loc - 1]) {
				visited[loc - 1] = true;
				q.push(make_pair(loc - 1, cnt + 1));
			}
		}
		if (0 <= (loc * 2) && (loc * 2) <= MAX_SIZE) {
			if (!visited[loc * 2]) {
				visited[loc * 2] = true;
				q.push(make_pair(loc * 2, cnt + 1));
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> k;
	
	visited[n] = true;
	BFS(n);
}