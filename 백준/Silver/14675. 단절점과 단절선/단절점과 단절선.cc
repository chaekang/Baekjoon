#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;

	graph.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int q;
	cin >> q;

	while (q--) {
		int t, k;
		cin >> t >> k;

		if (t == 1) {
			if (graph[k].size() > 1) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
		else if (t == 2) {
			cout << "yes\n";
		}
	}
	return 0;
}