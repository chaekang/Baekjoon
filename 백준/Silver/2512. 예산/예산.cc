#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0; // 지방의 수
	int money = 0; // 배정된 예산
	int max = 0; // 총 예산
	
	int answer = 0; // 답

	cin >> N;

	vector<int> v;

	// 각 지방의 예산요청 입력 받기
	for (int i{ 0 }; i < N; i++) {
		cin >> money;
		v.push_back(money);
	}

	cin >> max;

	sort(v.begin(), v.end());

	int start = 1; 
	int end = v.back();


	while (start <= end) {
		int mid = (start + end) / 2;
		int sum = 0;

		for (int i{ 0 }; i < v.size(); i++ ) {
			if (v[i] <= mid) {
				sum += v[i];
			}
			else {
				sum += mid;
			}
		}

		// 예산을 초과하는 경우
		if (sum > max) {
			end = mid - 1;
		}

		// 예산을 초과하지 않는 경우
		else {
			if (mid <= end) {
				answer = mid;
			}
			start = mid + 1;
		}
	}

	cout << answer;
}