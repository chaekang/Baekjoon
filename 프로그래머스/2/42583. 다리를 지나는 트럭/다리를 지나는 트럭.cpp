#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int now_weight = 0;
    int index = 0;

    queue<pair<int, int>> q;

    while (index < truck_weights.size() || !q.empty()) {
        answer++;

        if (!q.empty() && q.front().second == answer) {
            now_weight -= q.front().first;
            q.pop();
        }

        if (index < truck_weights.size() &&
            now_weight + truck_weights[index] <= weight) {

            now_weight += truck_weights[index];

            q.push({
                truck_weights[index],
                answer + bridge_length
            });

            index++;
        }
    }

    return answer;
}