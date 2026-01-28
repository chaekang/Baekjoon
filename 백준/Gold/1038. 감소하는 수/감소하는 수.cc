#include <iostream>
#include <queue>

using namespace std;

long long dp[10000001];

int main()
{
	int n;
	cin >> n;

	queue<long long> q;
	for (int i = 1; i <= 9; i++)
	{
		q.push(i);
		dp[i] = i;
	}
	if (n >= 0 && n <= 10) 
	{
		cout << n;
		return 0;
	}

	int idx = 10;
	while (idx <= n && !q.empty())
	{
		long long num = q.front();
		q.pop();

		int last = num % 10;
		for (int i = 0; i < last; i++)
		{
			q.push(num * 10 + i);
			dp[idx++] = num * 10 + i;
		}
	}

	if (idx >= n && dp[n] != 0)
		cout << dp[n];
	else cout << -1;
}