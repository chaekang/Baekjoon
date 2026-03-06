#include <iostream>
using namespace std;

int totalWolf;
int totalSheep;
int R, C;
char area[250][250];
bool visited[250][250];
//상하좌우
const int dy[4] = { 1,-1,0,0 };
const int dx[4] = { 0,0,1,-1 };

int currentWolf;
int currentSheep;
void DFS(int y, int x)
{
	visited[y][x] = true;
	if (area[y][x] == 'v')
		currentWolf++;
	if (area[y][x] == 'o')
		currentSheep++;
	for (int i = 0; i < 4; ++i)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if(ny >= 0 && ny < R && nx >= 0 && nx < C)
			if (!visited[ny][nx] && area[ny][nx] != '#')
			{
				DFS(ny, nx);
			}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for(int i=0; i<R; ++i)
		for (int j = 0; j < C; ++j)
		{
			cin >> area[i][j];
			if (area[i][j] == 'v')
				totalWolf++;
			if (area[i][j] == 'o')
				totalSheep++;
		}

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			currentSheep = 0;
			currentWolf = 0;
			// 한 영역을 구하는 DFS
			if (area[i][j] != '#' && !visited[i][j])
				DFS(i, j);

			if (currentWolf >= currentSheep)
				totalSheep -= currentSheep;
			else if (currentWolf < currentSheep)
				totalWolf -= currentWolf;
		}

	cout << totalSheep << " " << totalWolf << "\n";
	return 0;
}