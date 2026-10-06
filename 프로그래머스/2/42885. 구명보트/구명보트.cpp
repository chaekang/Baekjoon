#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());

    int left = 0;
    int right = people.size() - 1;
    int answer = 0;

    while (left <= right) {
        int tmpLimit = limit;
        int two = 2;

        while (left <= right &&
               tmpLimit - people[right] >= 0 &&
               two > 0) {

            tmpLimit -= people[right];
            right--;
            two--;
        }

        while (left <= right &&
               tmpLimit - people[left] >= 0 &&
               two > 0) {

            tmpLimit -= people[left];
            left++;
            two--;
        }

        answer++;
    }

    return answer;
}