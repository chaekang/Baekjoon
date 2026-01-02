#include <iostream>
#include <vector>
#include <algorithm>

void Init()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}

int main()
{
    Init();

    int TargetValue = 0;
    int NumCity = 0;

    std::cin >> TargetValue >> NumCity;

    std::vector<std::pair<int, int>> ADs(NumCity);
    for (int i = 0; i < NumCity; i++)
    {
        std::cin >> ADs[i].first;
        std::cin >> ADs[i].second;
    }

    std::vector<int> DP(100001);
    for (int i = 0; i < NumCity; i++)
    {
        for (int j = 1; j <= 100000; j++)
        {
            int Cost = ADs[i].first;
            int Mans = ADs[i].second;

            if (j - Cost >= 0)
            {
                DP[j] = std::max(DP[j], DP[j - Cost] + Mans);
            }
        }
    }

    int Answer = std::lower_bound(DP.begin(), DP.end(), TargetValue) - DP.begin();
    std::cout << Answer;

    return 0;
}