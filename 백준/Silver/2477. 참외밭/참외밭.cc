#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int k;
    cin >> k;

    vector<pair<int, int>> graph(6);
    for (int i = 0; i < 6; i++) {
        cin >> graph[i].first >> graph[i].second;
    }

    int max_width = 0, max_height = 0;
    int max_w_idx = -1, max_h_idx = -1;

    // 가장 긴 가로, 세로 변 찾기
    for (int i = 0; i < 6; i++) {
        if (graph[i].first <= 2) {  // 동(1), 서(2) → 가로 변
            if (max_width < graph[i].second) {
                max_width = graph[i].second;
                max_w_idx = i;
            }
        } else {  // 남(3), 북(4) → 세로 변
            if (max_height < graph[i].second) {
                max_height = graph[i].second;
                max_h_idx = i;
            }
        }
    }

    // 작은 직사각형 찾기: 가장 긴 변을 기준으로 양옆 변을 찾음
    int small_width = graph[(max_w_idx + 3) % 6].second;
    int small_height = graph[(max_h_idx + 3) % 6].second;

    // 전체 넓이 = 큰 직사각형 - 작은 직사각형
    int area = (max_width * max_height) - (small_width * small_height);
    cout << area * k << "\n";

    return 0;
}
