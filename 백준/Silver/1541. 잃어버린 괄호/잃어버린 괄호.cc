#include <iostream>
#include <string>

using namespace std;

int main()
{
	string formula;
	cin >> formula;

	int ans = 0;
	int tmp = 0;
	string num = "";
	bool isMinus = false;
	for (int i = 0; i <= formula.size(); i++)
	{
		if (formula[i] == '-' || formula[i] == '+' || i == formula.size())
		{
			tmp += stoi(num);
			num = "";

			if (formula[i] == '-' || i == formula.size())
			{
				if (isMinus)
				{
					ans -= tmp;
				}
				else
				{
					ans += tmp;
				}
				tmp = 0;
				isMinus = true;
			}

		}
		else
		{
			num += formula[i];
		}
	}

	cout << ans;
}