#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> v;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		str.erase(0, str.find('.') + 1);
		v.push_back(str);
	}
	sort(v.begin(), v.end());

	vector<pair<string, int>> ans;
	string tmp = v[0];
	int cnt = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (tmp == v[i]) cnt++;  // 같은 확장자 개수 세기
		else if (tmp != v[i]) // 새로운 확장자등장! 
		{
			// 확장자명이랑 이때까지 개수 센거 ans벡터에 담기 
			ans.push_back(pair<string, int>(tmp, cnt));
			// 다시 리셋
			tmp = v[i];
			cnt = 1;
		}
	}

	ans.push_back(pair<string, int>(tmp, cnt));

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}