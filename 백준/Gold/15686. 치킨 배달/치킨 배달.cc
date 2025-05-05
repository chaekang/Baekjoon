#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> house, chicken, picked;
bool selected[13];
int chickenDist = 9999999;

void MinDistance() {
	int result = 0;
	for (int i = 0; i < house.size(); i++) {
		int minDist = 99999999;
		for (int j = 0; j < picked.size(); j++) {
			minDist = min(minDist, abs(house[i].first - picked[j].first) + abs(house[i].second - picked[j].second));
		}
		result += minDist;
	}
	chickenDist = min(chickenDist, result);
}

void SelectChicken(int x, int cnt) {
	if (M == cnt) {
		MinDistance();
	}

	for (int i = x; i < chicken.size(); i++) {
		if (selected[i] == true) {
			continue;
		}

		selected[i] = true;
		picked.push_back({ chicken[i].first, chicken[i].second });
		SelectChicken(i, cnt + 1);
		selected[i] = false;
		picked.pop_back();
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;

			if (tmp == 1) {
				house.push_back({ i, j });
			}
			else if (tmp == 2) {
				chicken.push_back({ i, j });
			}
		}
	}

	SelectChicken(0, 0);

	cout << chickenDist;
}