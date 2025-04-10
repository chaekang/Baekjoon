#include <iostream>
#include <cmath>
#include <string>

using namespace std;


void HanoiTower(int n, int from, int mid, int to) {
	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	HanoiTower(n - 1, from, to, mid);
	cout << from << " " << to << "\n";
	HanoiTower(n - 1, mid, from, to);
}

int main() {
	int n;

	cin >> n;

	string a = to_string(pow(2, n));

	int x = a.find('.');				//pow 함수 결과가 실수형이기에 소수점 찾기
	a = a.substr(0, x);				//소수점 앞자리만 나오게하기
	a[a.length() - 1] -= 1;

	cout << a << "\n";

	if (n <= 20) {
		HanoiTower(n, 1, 2, 3);
	}
}