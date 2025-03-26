#include <iostream>
#include <vector>

using namespace std;

int n;
long long ans;
vector<int> node; // 실내(1), 실외(0)
vector<int> adj[200001];
bool visited[200001];

void dfs(int nodeIdx, int& cnt) {
    visited[nodeIdx] = true;

    for (int next : adj[nodeIdx]) {
        if (!visited[next]) 
        {
            if (node[next] == 0) {
                dfs(next, cnt);
            }
            else 
            {
                cnt++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    node.resize(n + 1);

    string s;
    cin >> s;

    for (int i = 1; i <= n; i++) {
        node[i] = s[i - 1] - '0';
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        if (node[a] == 1 && node[b] == 1) {
            ans += 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && node[i] == 0) {
            int cnt = 0;
            dfs(i, cnt);
            ans += 1LL * cnt * (cnt - 1);
        }
    }

    cout << ans;
}
