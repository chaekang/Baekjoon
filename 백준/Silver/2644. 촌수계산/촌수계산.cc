#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>> family;
vector<bool> visited;

void BFS(int p1, int p2) {
	queue<pair<int, int>> q;
	q.push({ p1, 0 });
	visited[p1] = true;

	while (!q.empty()) {
		int curPer = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (curPer == p2) {
			cout << depth;
			return;
		}

		for (int i = 0; i < family[curPer].size(); i++) {
			int x = family[curPer][i];
			if (!visited[x]) {
				q.push({ x, depth + 1 });
				visited[x] = true;
			}
		}
	}

	cout << "-1";
}

int main() {
	cin >> n;
	family.resize(n + 1);
	visited.resize(n + 1);

	int p1, p2;
	cin >> p1 >> p2;

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		family[x].push_back(y);
		family[y].push_back(x);
	}

	BFS(p1, p2);
}