#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int n;
    cin >> n;

    stack<char> left, right;

    // 초기 문자열 → 왼쪽 스택에 넣기
    for (char c : str) {
        left.push(c);
    }

    while (n--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        }
        else if (cmd == 'D') {
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        }
        else if (cmd == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        }
        else if (cmd == 'P') {
            char x;
            cin >> x;
            left.push(x);
        }
    }

    // 결과 출력
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }

    return 0;
}