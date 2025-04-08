#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 9999999

int v, e;
int k;
vector<pair<int, int>> graph[20001];
vector<int> ans;

void Dijkstra() {
	priority_queue<pair<int, int>> pq;  // 거리, 노드
	pq.push({ 0, k });  
	ans[k] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;  // 거리
		int cur = pq.top().second;   // 현재 노드
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;   // 다음 노드
			int cost = graph[cur][i].second;  // 가중치

			if (ans[next] > cost + dist) {
				ans[next] = cost + dist;
				pq.push(make_pair(-ans[next], next));
			}
		}
	}
}

int main() {
	cin >> v >> e;
	cin >> k;
	ans.resize(v + 1, INF);

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	Dijkstra();

	for (int i = 1; i <= v; i++) {
		if (ans[i] == INF) {
			cout << "INF" << "\n";
		}
		else {
			cout << ans[i] << "\n";
		}
	}
}