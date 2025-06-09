#include <iostream>
#include <vector>
using namespace std;

vector<int> students;
vector<bool> visited;
vector<bool> finished;
int ans;

void DFS(int x) {
    visited[x] = true;
    int next = students[x];

    if (!visited[next]) {
        DFS(next);
    }
    else if (!finished[next]) { // 사이클 발견
        for (int i = next; i != x; i = students[i]) {
            ans++;
        }
        ans++; // 자기 자신 포함
    }
    finished[x] = true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        students.clear(); students.resize(n + 1);
        visited.clear(); visited.resize(n + 1, false);
        finished.clear(); finished.resize(n + 1, false);
        ans = 0;

        for (int i = 1; i <= n; ++i) {
            cin >> students[i];
        }

        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                DFS(i);
            }
        }

        cout << n - ans << "\n";
    }
}
