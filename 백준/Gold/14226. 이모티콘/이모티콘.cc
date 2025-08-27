#include <iostream>
#include <queue>

using namespace std;

int s;
bool visited[2001][2001];

int BFS() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 0), 0));

	while (!q.empty()) {
		int screen = q.front().first.first;
		int clip = q.front().first.second;
		int time = q.front().second;

		q.pop();

		if (screen == s) {
			return time;
		}

		if (screen > 0 && screen < 2000) {
			if (visited[screen][screen] == false) {
				visited[screen][screen] = true;
				q.push(make_pair(make_pair(screen, screen), time + 1));
			}

			if (visited[screen - 1][clip] == false) {
				visited[screen - 1][clip] = true;
				q.push(make_pair(make_pair(screen - 1, clip), time + 1));
			}
		}

		if (clip > 0 && screen + clip < 2000) {
			if (visited[screen + clip][clip] == false) {
				visited[screen + clip][clip] = true;
				q.push(make_pair(make_pair(screen + clip, clip), time + 1));
			}
		}
	}
}

int main() {
	cin >> s;

	int ans = BFS();

	cout << ans;
}