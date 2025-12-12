#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	priority_queue<int,vector<int>,greater<int>>ans;
	for(int i=0;i<n;i++)
	{
		int s,e;
		cin>>s>>e;
		pq.push(make_pair(s,e));
	}
	ans.push(pq.top().second);
	pq.pop();
	while(!pq.empty())
	{
		if(ans.top()<=pq.top().first)
		{
			ans.push(pq.top().second);
			ans.pop();
		}
		else
		{
			ans.push(pq.top().second);
		}
		pq.pop();
	}
	cout<<ans.size();
}