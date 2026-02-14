#include <iostream>
using namespace std;

int main()
{
    int n;

    while (cin >> n)
    {
        int num = 1 % n;
        int len = 1;

        while (num != 0)
        {
            num = (num * 10 + 1) % n;
            len++;
        }

        cout << len << '\n';
    }
}
