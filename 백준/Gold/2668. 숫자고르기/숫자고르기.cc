#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n;
vector<int> second;
vector<int> ans;
bool visited[101] = { false, };

void DFS(int firstNum, int num) {
	if (visited[num]) {
		if (firstNum == num) {
			ans.push_back(num);
		}
		return;
	}

	visited[num] = true;
	DFS(firstNum, second[num]);
}

int main() {
	cin >> n;

	second.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> second[i];
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		DFS(i, i);
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}