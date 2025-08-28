#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> v[100001];
int maxCost = 0;

bool bfs(int mid, int n, int a, int b)
{
    queue<int> q;
    vector<int> visited(n + 1, 0);
    visited[a] = 1;
    q.push(a);

    while (!q.empty())
    {
        int pos = q.front();
        q.pop();

        if (pos == b)
            return true;

        for (int i = 0; i < v[pos].size(); i++)
        {
            int w = v[pos][i].first;
            int npos = v[pos][i].second;

            if (npos >= 1 && npos <= n && !visited[npos] && w >= mid)
            {
                visited[npos] = 1;
                q.push(npos);
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ c, b });
        v[b].push_back({ c, a });
        maxCost = max(maxCost, c);
    }

    int a, b;
    cin >> a >> b;

    int start = 0;
    int end = maxCost;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (bfs(mid, n, a, b))
            start = mid + 1;
        else
            end = mid - 1;
    }
    cout << end;
}
