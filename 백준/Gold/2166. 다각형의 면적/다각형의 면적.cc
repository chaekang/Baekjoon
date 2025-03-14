#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
vector<pair<ll, ll>> graph;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		graph.push_back({ x, y });
	}

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		int next = (i + 1) % n;
		sum += graph[i].first * graph[next].second;
		sum -= graph[next].first * graph[i].second;
	}

	double result = abs(sum) / 2.0;

	cout << fixed;
	cout.precision(1);
	cout << result << "\n";
}