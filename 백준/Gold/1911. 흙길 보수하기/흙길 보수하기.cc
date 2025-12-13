#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, l; 
	cin >> n >> l; 
	vector <pair <int, int>>v; 
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; 
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end()); 
	int s, e; 
	s = v[0].first; 
	e = v[0].first+l;
	int cnt = 0; 
	for (int i = 0; i < v.size(); i++) {
		if (s < v[i].first) {
			s = v[i].first; 
			e = v[i].first + l; 
		}
		while (s < v[i].second) {
			cnt++;
			s = e;
			e = s + l;
		}		
	}
	cout << cnt; 
}
