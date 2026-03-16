#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long arr[100001];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int left = 0;
    int right = n - 1;

    long long x = 0;
    long long y = 0;
    long long ans = LLONG_MAX;

    while (left < right)
    {
        long long sum = arr[left] + arr[right];

        if (llabs(sum) < llabs(ans))
        {
            ans = sum;
            x = arr[left];
            y = arr[right];
        }

        if (sum == 0)
        {
            break;
        }
        else if (sum > 0)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    cout << x << " " << y;
}