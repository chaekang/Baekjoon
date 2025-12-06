#include <iostream>
#include <vector>

using namespace std;

vector<int> in, post, pre;
int idx[100001];

void preorder(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd || postStart > postEnd)
		return;

	int root = post[postEnd];
	int rootIndex = idx[root];
	int leftSize = rootIndex - inStart;
	int rightSize = inEnd - rootIndex;

	cout << root << " ";

	preorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
	preorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		in.push_back(x);
		idx[x] = i;
	}

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		post.push_back(x);
	}

	preorder(0, n - 1, 0, n - 1);
}