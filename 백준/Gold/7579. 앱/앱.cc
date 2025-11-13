#include<iostream>
using namespace std;

int N, M;
int dp[10001];
int A[101];
int c[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i=1; i<=N; i++)
        cin >> A[i];

    for (int i=1; i<=N; i++)
        cin >> c[i];

    for (int i=1; i<=N; i++) {
        for (int j=10000; j>=c[i]; j--) {
            dp[j] = max(dp[j], dp[j - c[i]] + A[i]);
        }
    }

    int cost = 0;
    while (dp[cost] < M) cost++;
    cout << cost;

    return 0;
}
