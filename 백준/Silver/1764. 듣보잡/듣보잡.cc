#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> see;
	vector<string> hear;
	vector<string> result;

	while (n--) {
		string name;
		cin >> name;
		see.push_back(name);
	}
	while (m--) {
		string name;
		cin >> name;
		hear.push_back(name);
	}

	sort(see.begin(), see.end());
	sort(hear.begin(), hear.end());

	result.resize(see.size() + hear.size());
	auto itr = set_intersection(see.begin(), see.end(), hear.begin(), hear.end(), result.begin());
	result.erase(itr, result.end());

	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
}