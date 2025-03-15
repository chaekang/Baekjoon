#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<int, int>> graph;

// 점을 정렬하여 올바른 순서로 배치
void sortPoints() {
    sort(graph.begin(), graph.end()); // (x, y) 기준 정렬
    vector<pair<int, int>> sorted(4);
    sorted[0] = graph[0]; // 왼쪽 아래
    sorted[2] = graph[3]; // 오른쪽 위
    sorted[1] = (graph[1].second > graph[2].second) ? graph[1] : graph[2]; // 오른쪽 아래
    sorted[3] = (graph[1].second < graph[2].second) ? graph[1] : graph[2]; // 왼쪽 위
    graph = sorted;
}

// 두 점 사이 거리의 제곱을 구하는 함수
int distSquared(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) +
        (a.second - b.second) * (a.second - b.second);
}

// 정사각형 판별 함수
int Square() {
    sortPoints(); // 점 정렬

    // 네 변의 길이 계산
    int d1 = distSquared(graph[0], graph[1]);
    int d2 = distSquared(graph[1], graph[2]);
    int d3 = distSquared(graph[2], graph[3]);
    int d4 = distSquared(graph[3], graph[0]);

    // 두 대각선의 길이 계산
    int diag1 = distSquared(graph[0], graph[2]);
    int diag2 = distSquared(graph[1], graph[3]);

    if (d1 != d2 || d2 != d3 || d3 != d4) {
        return 0;
    }

    if (diag1 != diag2) {
        return 0;
    }

    return 1;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        graph.clear();
        for (int j = 0; j < 4; j++) {
            int x, y;
            cin >> x >> y;
            graph.push_back({ x, y });
        }
        cout << Square() << "\n";
    }
}
