#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> graph(12, 0);

	graph[1] = 1;
	graph[2] = 2;
	graph[3] = 4;

	for (int i = 4; i < 12; i++) {
		graph[i] = graph[i - 1] + graph[i - 2] + graph[i - 3];
	}

	int t;

	for (int i = 0; i < n; i++) {
		cin >> t;
		cout << graph[t] << "\n";
	}
}