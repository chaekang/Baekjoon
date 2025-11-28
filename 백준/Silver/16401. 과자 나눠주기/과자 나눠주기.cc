#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<int> v;
int mid = 0;

void BinarySearch(int start, int end)
{
	int cnt = 0;
	mid = (start + end) / 2;
	for (int i = 0; i < n; i++)
	{
		cnt += v[i] / mid;
	}

	if (cnt > m)
	{
		BinarySearch(mid + 1, end);
	}
	else if (cnt < m)
	{
		BinarySearch(start, mid - 1);
	}
	else
	{
		return;
	}
}

int main() {
	cin >> m >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int start = 1; 
	int end = *max_element(v.begin(), v.end());
	int result = 0;

	while (start <= end) {
		int mid = (start + end) / 2;

		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += v[i] / mid;
		}

		if (cnt >= m) {
			result = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << result;
}