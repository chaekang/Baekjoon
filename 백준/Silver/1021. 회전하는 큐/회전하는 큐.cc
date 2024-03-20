#include <iostream>
#include <deque>

using namespace std;

int main(void) 
{
	int N, M, num;
	int count = 0;
	int index;

	cin >> N >> M;

	deque<int> DQ;

	for (int i = 1; i <= N; i++) {
		DQ.push_back(i);
	}

	while (M--) {

		cin >> num;

		for (int i = 0; i < DQ.size(); i++) {
			if (DQ[i] == num) {
				index = i;
				break;
			}
		}

		if (index <= DQ.size() / 2) {
			while (1) {
				if (DQ.front() == num) {
					DQ.pop_front();
					break;
				}

				DQ.push_back(DQ.front());
				DQ.pop_front();
				++count;
			}
		}
		else {
			while (1) {
				if (DQ.front() == num) {
					DQ.pop_front();
					break;
				}
				DQ.push_front(DQ.back());
				DQ.pop_back();
				++count;
			}

		}
	}

	cout << count;
	return 0;
}