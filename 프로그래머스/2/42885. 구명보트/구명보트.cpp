#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int left = 0;
    int right = people.size() - 1;
    
    while (left <= right) {
        int twoPeople = 2;
        answer++;
        int leftLimit = limit;
        while (leftLimit - people[right] >= 0 && twoPeople > 0) {
            leftLimit -= people[right];
            right--;
            twoPeople--;
        }
        while (leftLimit - people[left] >= 0 && twoPeople > 0) {
            leftLimit -= people[left];
            left++;
            twoPeople--;
        }
    }
    
    return answer;
}