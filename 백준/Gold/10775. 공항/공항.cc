#include <iostream>
#include <vector>

using namespace std;

int airplane[100001];

int Find(int a) {
	if (airplane[a] == a) {
		return a;
	}
	else {
		return airplane[a] = Find(airplane[a]);
	}
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);

	if (A > B) {
		swap(A, B);
	}
	airplane[B] = A;
}

int main() {
	int g;
	cin >> g;

	int p;
	cin >> p;

	int ans = 0;
	for (int i = 0; i <= g; i++) {
		airplane[i] = i;
	}

	for (int i = 0; i < p; i++) {
		int x;
		cin >> x;

		int X = Find(x);
		if (X == 0) break;

		Union(X, X - 1);
		ans++;
	}
	cout << ans;
}