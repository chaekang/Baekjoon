#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> jewels[300001];
int bag[300001];
int k;
int n;
priority_queue<int, vector<int>, less<int>> pq;

long long Robbery() {
    sort(jewels, jewels + n);
    sort(bag, bag + k);

    int idx = 0;
    long long ans = 0;

    for (int i = 0; i < k; i++) {
        while (idx < n && bag[i] >= jewels[idx].first) {
            pq.push(jewels[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    return ans;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> jewels[i].first >> jewels[i].second;
	}
	
	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}
    cout << Robbery();
}