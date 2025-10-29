#include <iostream>
#include <vector>

using namespace std;

int parents[51];

int Find(int x) {
    if (parents[x] == x) return x;
    return x = Find(parents[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    parents[x] = y;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> truth;
	int k;
    cin >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		truth.push_back(x);
	}

	vector<int> party[51];
    for (int i = 1; i <= n; i++) parents[i] = i;

    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        int num;
        int prev;
        for (int j = 0; j < p; j++) {
            if (j >= 1) {
                prev = num;
                cin >> num;
                Union(prev, num);
            }
            else {
                cin >> num;
            }
            party[i].push_back(num);
        }
    }
    for (auto& list : party) {
        bool flag = false;
        for (auto& person : list) {
            if (flag) break;
            for (auto& t : truth) {
                if (Find(person) == Find(t)) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)m--;
    }
    cout << m;
}