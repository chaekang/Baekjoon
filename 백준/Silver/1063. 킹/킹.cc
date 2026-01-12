#include <iostream>

using namespace std;

int main()
{
	int n;
	string king, stone;
	cin >> king >> stone >> n;
	int kx = king[0] - 64;
	int ky = king[1] - 48;
	int sx = stone[0] - 64;
	int sy = stone[1] - 48;

	while (n--)
	{
		string m;
		cin >> m;
		int mx = 0;
		int my = 0;
		if (m == "R") mx = 1;
		else if (m == "L") mx = -1;
		else if (m == "B") my = -1;
		else if (m == "T") my = 1;
		else if (m == "RT") { mx = 1; my = 1; }
		else if (m == "LT") { mx = -1; my = 1; }
		else if (m == "RB") { mx = 1; my = -1; }
		else if (m == "LB") { mx = -1; my = -1; }

		int cur_kx = kx + mx;
		int cur_ky = ky + my;
		int cur_sx = sx + mx;
		int cur_sy = sy + my;

		if (cur_kx < 1 || cur_kx > 8 || cur_ky < 1 || cur_ky>8) continue;

		if (cur_kx == sx && cur_ky == sy)
		{
			if (cur_sx < 1 || cur_sx > 8 || cur_sy < 1 || cur_sy>8) continue;
			sx = cur_sx;
			sy = cur_sy;
		}
		kx = cur_kx;
		ky = cur_ky;
	}

	cout << (char)(kx + 64) << ky << "\n";
	cout << (char)(sx + 64) << sy;
}