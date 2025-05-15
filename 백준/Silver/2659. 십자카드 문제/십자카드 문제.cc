#include <iostream>
#include <algorithm>

using namespace std;

int GetNumber(int a, int b, int c, int d) {
	int num1 = a * 1000 + b * 100 + c * 10 + d;
	int num2 = b * 1000 + c * 100 + d * 10 + a;
	int num3 = c * 1000 + d * 100 + a * 10 + b;
	int num4 = d * 1000 + a * 100 + b * 10 + c;

	return min({ num1, num2, num3, num4 });
}

int isCircleNum(int num) {
	int temp = num;
	for (int i = 0; i < 3; i++) {
		num = num % 1000 * 10 + num / 1000;
		if (temp > num) {
			temp = num;
		}
	}
	return temp;
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int minNum = GetNumber(a, b, c, d);

	int ans = 0;
	for (int i = 1111; i <= minNum; i++) {
		if (isCircleNum(i) == i) {
			ans++;
		}
	}
	cout << ans;
}