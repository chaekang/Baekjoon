#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> node;
vector<vector<int>> tree;
vector<bool> visited;
long long result = 0;

// 실외를 기준으로 탐색하여 연결된 실내 개수 찾기
int Walk(int x) {
    visited[x] = true;
    int indoorCnt = 0;

    for (int neighbour : tree[x]) {
        if (visited[neighbour]) continue;  // 이미 방문한 노드는 패스

        if (node[neighbour] == 1) {  // 실내인 경우
            indoorCnt++;
            result++;  // 실외를 통해 연결 가능한 경로 추가
        }
        else {  // 실외라면 계속 탐색
            indoorCnt += Walk(neighbour);
        }
    }
    return indoorCnt;
}

int main() {
    cin >> n;

    tree.resize(n + 1);
    node.resize(n + 1);
    visited.resize(n + 1, false);

    string arr;
    cin >> arr;

    for (int i = 1; i <= n; i++) {
        node[i] = arr[i - 1] - '0';  // '0', '1'을 정수로 변환
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    // 1. 실내끼리 바로 연결된 경우 찾기
    for (int i = 1; i <= n; i++) {
        if (node[i] == 1) {  // 현재 노드가 실내라면
            for (int neighbour : tree[i]) {
                if (node[neighbour] == 1) { // 연결된 노드도 실내라면
                    result++;
                }
            }
        }
    }
    result /= 2; // 중복 계산 제거

    // 2. 실외를 경유하여 연결된 실내 쌍 찾기
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && node[i] == 0) {  // 방문하지 않은 실외 노드 탐색
            int indoorCnt = Walk(i);  // 연결된 실내 개수 확인
            result += 1LL * indoorCnt * (indoorCnt - 1); // 실외를 통한 실내 쌍 계산
        }
    }

    cout << result;
}
