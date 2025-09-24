#include <iostream>

using namespace std;

int n, r, c;
int ans = 0;

void Divide(int x, int y, int size) {
    if (size == 1) {
        return;
    }

    int half = size / 2;

    if (r < x + half && c < y + half) {
        Divide(x, y, half);
    }
    else if (r < x + half && c >= y + half) {
        ans += half * half;
        Divide(x, y + half, half);
    }
    else if (r >= x + half && c < y + half) {
        ans += 2 * half * half; 
        Divide(x + half, y, half);
    }
    else {
        ans += 3 * half * half;
        Divide(x + half, y + half, half);
    }
}

int main() {
	cin >> n >> r >> c;

	Divide(0, 0, (1 << n));
    cout << ans;
}