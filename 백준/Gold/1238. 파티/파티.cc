#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define INF 999999

int n, m, x;
vector<pair<int, int>> graph[1001];
int dist[1001];

int Dijkstra(int start, int end) {
	for (int i = 1; i <= n; i++) dist[i] = INF;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int time = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist[node] < time) continue;

		for (int i = 0; i < graph[node].size(); i++) {
			int next_time = graph[node][i].first + time;
			int next_node = graph[node][i].second;

			if (dist[next_node] > next_time) {
				dist[next_node] = next_time;
				pq.push(make_pair(next_time, next_node));
			}
		}
	}

	return dist[end];
}

int main() {
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int start, end, time;
		cin >> start >> end >> time;

		graph[start].push_back(make_pair(time, end));
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int go = Dijkstra(i, x);
		int back = Dijkstra(x, i);
		int tmp = go + back;

		if (tmp > ans) {
			ans = tmp;
		}
	}

	cout << ans;
}