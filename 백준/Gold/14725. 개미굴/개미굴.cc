#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<string> v[1000];

string line(int k) {
    string ret;
    while (k--) ret += "--";
    return ret;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        vector<string> t;
        cin >> K;
        while (K--) {
            string s;
            cin >> s;
            t.push_back(s);
        }
        v[i] = t;
    }

    // 🔧 비교 함수 명시적으로 지정
    sort(v, v + N, [](const vector<string>& a, const vector<string>& b) {
        return a < b;   // vector<string>의 사전순 비교
    });

    for (int i = 0; i < N; i++) {
        int d = 0;
        if (i != 0) {
            for (int j = 0; j < v[i].size() && j < v[i - 1].size(); j++) {
                if (v[i][j] == v[i - 1][j]) d++;
                else break;
            }
        }
        for (int j = d; j < v[i].size(); j++)
            cout << line(j) + v[i][j] << '\n';
    }
}
