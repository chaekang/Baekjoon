#include <iostream>
#include <vector>

using namespace std;

int r, c, n;
vector<string> explode(const vector<string>& board)
{
	vector<string> res(r, string(c, 'O'));

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'O')
			{
				res[i][j] = '.';
				for (int d = 0; d < 4; d++)
				{
					int ni = i + dx[d];
					int nj = j + dy[d];
					if (ni >= 0 && ni < r && nj >= 0 && nj < c)
						res[ni][nj] = '.';
				}
			}
		}
	}
	return res;
}

int main()
{
	cin >> r >> c >> n;
	vector<string> board(r);
	for (int i = 0; i < r; i++)
	{
		cin >> board[i];
	}

	if (n == 1)
	{
		for (auto& s : board) cout << s << '\n';
		return 0;
	}


	if (n % 2 == 0)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
				cout << 'O';
			cout << '\n';
		}
		return 0;
	}

	vector<string> first = explode(board);
	if (n % 4 == 3)
	{
		for (auto& s : first) cout << s << '\n';
		return 0;
	}

	vector<string> second = explode(first);

	for (auto& s : second) cout << s << '\n';
	return 0;
}