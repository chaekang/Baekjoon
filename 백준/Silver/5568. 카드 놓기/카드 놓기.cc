#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, k;
vector<string> v;
set<string> ans;
vector<bool> visited;

void Permutation(string num, int cnt) {
	if (cnt == k) {
		ans.insert(num);
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			Permutation(num + v[i], cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> k;
	
	visited.resize(n, false);

	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		v.push_back(x);
	}

	Permutation("", 0);
	cout << ans.size();
}