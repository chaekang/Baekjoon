#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;

	stack<char> st;
	stack<char> st2;

    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        while (!st.empty() && cnt < k && str[i] > st.top())
        {
            cnt++;
            st.pop();
        }
        st.push(str[i]);
    }

    while (cnt < k)
    {
        cnt++;
        st.pop();
    }

    while (!st.empty())
    {
        st2.push(st.top());
        st.pop();
    }

    while (!st2.empty())
    {
        cout << st2.top();
        st2.pop();
    }
}