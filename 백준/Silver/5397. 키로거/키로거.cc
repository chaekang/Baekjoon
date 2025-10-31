#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;

        list<char> ans;
        auto cursor = ans.begin();

        for (char c : str) {
            if (c == '<') {
                if (cursor != ans.begin()) --cursor;
            }
            else if (c == '>') {
                if (cursor != ans.end()) ++cursor;
            }
            else if (c == '-') {
                if (cursor != ans.begin()) {
                    cursor = ans.erase(--cursor);
                }
            }
            else {
                ans.insert(cursor, c);
            }
        }

        for (char c : ans) cout << c;
        cout << "\n";
    }
}
