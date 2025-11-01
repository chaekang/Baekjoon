#include <iostream>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
        multiset<int> q;
		for (int i = 0; i < k; i++) {
			char c;
			int n;
			cin >> c >> n;

            if (c == 'I') {
                q.insert(n);
            }
            else if (c == 'D') {
                if (q.empty()) {
                    continue;
                }
                else if (n == 1) {
                    auto iter = q.end();
                    iter--;
                    q.erase(iter);
                }
                else if (n == -1) {
                    q.erase(q.begin());
                }
            }
        }
        if (q.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            auto iter = q.end();
            iter--;
            cout << *iter << " " << *q.begin() << '\n';
        }
	}
}