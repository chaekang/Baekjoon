#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	map<string, int> trees;
	string name;
	float cnt = 0;

	while (getline(cin, name) && !name.empty()) {
		cnt++;
		auto it = trees.find(name);
		if (it == trees.end()) {
			trees[name] = 1;
		}
		else {
			trees[name] += 1;
		}
	}

	cout << fixed;
	cout.precision(4);

	for (auto it = trees.begin(); it != trees.end(); it++) {
		float value = (it->second / cnt) * 100;
		cout << it->first << " ";
		cout << value << "\n";
	}
}