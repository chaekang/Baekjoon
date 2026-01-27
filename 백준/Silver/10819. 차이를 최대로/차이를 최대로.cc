#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int n[9];
    int result = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }

    sort(n, n + N);

    do {
        int tmp = 0;
        for (int i = 0; i < N - 1; i++) {
            tmp += abs(n[i + 1] - n[i]);
        }
        result = max(result, tmp);
    } while (next_permutation(n, n + N));

    cout << result << endl;
}
