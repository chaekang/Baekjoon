#include <iostream>

using namespace std;

long long pill[31][31];

int main()
{
	for (int i = 0; i <= 30; i++)
	{
		pill[0][i] = 1;
	}

	for (int i = 1; i <= 30; i++)
	{
		for (int j = i; j <= 30; j++)
		{
			if (i == j)
			{
				for (int k = 0; k < i; k++)
				{
					pill[i][j] += pill[k][j - 1];
				}
			}
			else
			{
				pill[i][j] = pill[i - 1][j] + pill[i][j - 1];
			}
		}
	}

	int n;
	while (1)
	{
		cin >> n;
		if (n == 0) break;

		cout << pill[n][n] << "\n";
	}
}