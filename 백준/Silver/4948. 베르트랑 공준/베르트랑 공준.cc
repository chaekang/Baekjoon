#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    int root = sqrt(num);
    for (int i = 3; i <= root; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        int ans = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            if (isPrime(i)) ans++;
        }
        cout << ans << "\n";
        cin >> n;
    }
}
