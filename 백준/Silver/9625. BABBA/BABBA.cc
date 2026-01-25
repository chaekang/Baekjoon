#include <iostream>

using namespace std;

int main()
{
	int A[46];
	int B[46];
	
	int k;
	cin >> k;

	A[0] = 1;
	B[0] = 0;

	for (int i = 1; i <= k; i++)
	{
		A[i] = B[i - 1];
		B[i] = A[i - 1] + B[i - 1];
	}

	cout << A[k] << " " << B[k];
}