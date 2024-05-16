#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int cnt = 0;
int square[25][25];
bool visited[25][25];
vector<int> house_cnt;
int x_dir[4] = { -1, 1, 0, 0 };
int y_dir[4] = { 0, 0, 1, -1 };

void DFS(int a, int b) {
	visited[a][b] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int x = a + x_dir[i];
		int y = b + y_dir[i];

		if (x >= 0 && x < n && y >= 0 && y < n && square[x][y] == 1 && visited[x][y] == false) {
			DFS(x, y);
		}
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			square[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (square[i][j] == 1 && visited[i][j] == false) {
				cnt = 0;
				DFS(i, j);
				house_cnt.push_back(cnt);
			}
		}
	}

	sort(house_cnt.begin(), house_cnt.end());

	int size = house_cnt.size();
	cout << size << "\n";

	for (int i = 0; i < size; i++) {
		cout << house_cnt[i] << "\n";
	}
}