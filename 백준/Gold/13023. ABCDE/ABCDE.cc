#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[2001];
bool visited[2001];
int ans = 0;

void DFS(int cur, int cnt) {
	if (cnt == 5) {
		ans = 1;
		return;
	}

	for (int i = 0; i < v[cur].size(); i++) {
		if (visited[v[cur][i]] == false) {
			visited[v[cur][i]] = true;
			DFS(v[cur][i], cnt + 1);
			visited[v[cur][i]] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		visited[i] = true;
		DFS(i, 1);
		if (ans == 1) {
			break;
		}
		visited[i] = false;
	}

	cout << ans;
}