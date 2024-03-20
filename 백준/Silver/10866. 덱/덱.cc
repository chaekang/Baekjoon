#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    int N;
    deque<int> dq;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string user_input;
        cin >> user_input;

        if (user_input == "push_front") {
            int X;
            cin >> X;
            dq.push_front(X);
        }
        else if (user_input == "push_back") {
            int X;
            cin >> X;
            dq.push_back(X);
        }
        else if (user_input == "pop_front") {
            if (!dq.empty()) {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
            else {
                cout << "-1\n";
            }
        }
        else if (user_input == "pop_back") {
            if (!dq.empty()) {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
            else {
                cout << "-1\n";
            }
        }
        else if (user_input == "size") {
            cout << dq.size() << "\n";
        }
        else if (user_input == "empty") {
            if (dq.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (user_input == "front") {
            if (!dq.empty()) {
                cout << dq.front() << "\n";
            }
            else {
                cout << "-1\n";
            }
        }
        else if (user_input == "back") {
            if (!dq.empty()) {
                cout << dq.back() << "\n";
            }
            else {
                cout << "-1\n";
            }
        }
    }
}