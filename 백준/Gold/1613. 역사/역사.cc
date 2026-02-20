#include <iostream>
#include <vector>
#include <list>

using namespace std;

int n, k, f, b, s;
constexpr int MAX = 401;
vector<pair<int, int>> graph[MAX];
list<pair<int, int>> myList;
int disArr[MAX][MAX];

int main()
{
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> f >> b;
        graph[f].push_back(make_pair(b, -1));
        graph[b].push_back(make_pair(f, 1));
    }

    cin >> s;
    pair<int, int> tempP;
    while (s--) 
    {
        cin >> tempP.first >> tempP.second;
        myList.push_back(tempP);
    }
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 0; j < graph[i].size(); j++) 
        {
            int v = graph[i][j].first;
            int weight = graph[i][j].second;
            disArr[i][v] = weight;
        }
    }
    for (int k = 1; k <= n; k++) 
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (i == j) disArr[i][j] = 0;
                else if (disArr[i][k] == 1 && disArr[k][j] == 1) disArr[i][j] = 1;
                else if (disArr[i][k] == -1 && disArr[k][j] == -1) disArr[i][j] = -1;
            }
        }
    }
    for (auto it = myList.begin(); it != myList.end(); it++) 
    {
        cout << disArr[it->first][it->second] << "\n";
    }
    return 0;
}