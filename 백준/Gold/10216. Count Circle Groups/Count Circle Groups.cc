#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct circle {
	int x, y;
	int r;
};

vector<circle> v;
int parent[3000];

int FindParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = FindParent(parent[x]);
}

void Union(int a, int b) {
	int pa = FindParent(a);
	int pb = FindParent(b);
	if (pa != pb) {
		parent[pa] = pb;
	}
}

bool CheckDist(int i, int j) {
	circle c1 = v[i];
	circle c2 = v[j];
	long long dx = c1.x - c2.x;
	long long dy = c1.y - c2.y;
	long long distSq = dx * dx + dy * dy;
	long long radSum = c1.r + c2.r;
	return distSq <= radSum * radSum;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int original_n = n;

		v.clear();

		for (int i = 0; i < n; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			v.push_back({ x, y, r });
			parent[i] = i;
		}

		int ans = original_n;
		for (int i = 0; i < original_n - 1; i++) {
			for (int j = i + 1; j < original_n; j++) {
				if (FindParent(i) == FindParent(j)) continue;
				if (CheckDist(i, j)) {
					Union(i, j);
					ans--;
				}
			}
		}
		cout << ans << "\n";
	}
}
