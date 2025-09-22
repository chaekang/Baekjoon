#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> um;
unordered_map<string, int> nums;

string Find(string a) {
	if (um[a] == a) {
		return a;
	}
	else {
		return um[a] = Find(um[a]);
	}
}

void Union(string a, string b) {
	string A = Find(a);
	string B = Find(b);

	if (A == B) {
		return;
	}

	um[B] = A;
	nums[A] += nums[B];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int f;
		cin >> f;

		um.clear();
		nums.clear();

		for (int j = 0; j < f; j++) {
			string a, b;
			cin >> a >> b;

			if (um.count(a) == 0) {
				um.insert(make_pair(a, a));
				nums.insert(make_pair(a, 1));
			}

			if (um.count(b) == 0) {
				um.insert(make_pair(b, b));
				nums.insert(make_pair(b, 1));
			}

			Union(a, b);
			cout << nums[Find(a)] << "\n";
		}
	}
}