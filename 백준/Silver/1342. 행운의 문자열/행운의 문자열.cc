#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    int answer = 0;
    do {
        bool lucky = true;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                lucky = false;
                break;
            }
        }

        if (lucky)
            answer++;
    } 
    while (next_permutation(s.begin(), s.end()));
    cout << answer;

}
