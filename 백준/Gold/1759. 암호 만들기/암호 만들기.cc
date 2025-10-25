#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> arr;
vector<char> tmp;
int l, c;

bool Check(vector<char> v) {
	int vowel = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
			vowel++;
		}
	}
	if (vowel >= 1 && l - vowel >= 2) {
		return true;
	}
	return false;
}

void DFS(int idx) {
	if ((int)tmp.size() == l) {
		if (Check(tmp)) {
			for (int i = 0; i < tmp.size(); i++) {
				cout << tmp[i];
			}
			cout << "\n";
		}
		return;
	}

	for (int i = idx; i < c; i++) {
		tmp.push_back(arr[i]);
		DFS(i + 1);
		tmp.pop_back();
	}
}

int main() {
	cin >> l >> c;

	for (int i = 0; i < c; i++) {
		char x;
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());
	DFS(0);

}