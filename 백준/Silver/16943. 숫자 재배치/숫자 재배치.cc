#include <iostream>
#include <vector>
#include <string>

using namespace std;

string a;
int b;
int n;

vector<char> v;
vector<bool> visited;
int ans = -1;

void Recursive(int num) {
	if (num >= 1 && v[0] == '0') {
		return;
	}

	if (num == n) {
		string tmp = "";
		for (int i = 0; i < num; i++) {
			tmp += v[i];
		}

		int t = stoi(tmp);
		if (t != 0 && t < b) {
			ans = max(ans, t);
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v[num] = a[i];
			Recursive(num + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> a >> b;

	n = a.length();
	visited.resize(n, false);
	v.resize(n);

	Recursive(0);

	cout << ans;
}