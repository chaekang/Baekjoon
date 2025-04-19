#include <vector>
#include <iostream>

using namespace std;

int n;
vector<int> lotto;
vector<int> ans;

void DFS(int start, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < n; i++) {
		ans[depth] = lotto[i];
		DFS(i + 1, depth + 1);
	}
}

int main() {
	ans.resize(6);
	cin >> n;
	while (n != 0) {
		lotto.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> lotto[i];
		}

		DFS(0, 0);
		cout << "\n";

		cin >> n;
	}
}