#include <iostream>

using namespace std;

int dist[100];

int main() 
{
	int R, C;
	int dirX, lX, distX;
	int ans = 0;

	cin >> C >> R;

	int K; 
	cin >> K;
	for (int k = 0; k < K; k++) 
	{
		int dir, l; 
		cin >> dir >> l;
		if (dir == 1) 
			dist[k] = l;
		else if (dir == 4) 
			dist[k] = C + l;
		else if (dir == 2) 
			dist[k] = C + R + (C - l);
		else 
			dist[k] = C + R + C + (R - l);
	}

	cin >> dirX >> lX;
	if (dirX == 1) 
		distX = lX;
	else if (dirX == 4) 
		distX = C + lX;
	else if (dirX == 2) 
		distX = C + R + (C - lX);
	else 
		distX = C + R + C + (R - lX);

	for (int k = 0; k < K; k++) 
	{
		int tmp = abs(dist[k] - distX);
		ans += min(tmp, 2 * R + 2 * C - tmp);
	}

	cout << ans;
}