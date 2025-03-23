#include <iostream>
#include <vector>

using namespace std;

int n, del, root;
vector<int> tree[51]; // 각 노드의 자식 리스트
bool deleted[51];     // 삭제 여부를 저장하는 배열

// 노드를 삭제하고 모든 자식도 삭제
void deleteNode(int node) {
    deleted[node] = true;
    for (int child : tree[node]) {
        deleteNode(child);
    }
}

// 리프 노드 개수 계산
int countLeaves(int node) {
    if (deleted[node]) return 0; // 삭제된 노드는 무시

    if (tree[node].empty()) return 1; // 자식이 없는 경우 리프 노드

    int leafCount = 0;
    bool hasChild = false;

    for (int child : tree[node]) {
        if (!deleted[child]) { // 삭제되지 않은 자식만 고려
            leafCount += countLeaves(child);
            hasChild = true;
        }
    }

    return hasChild ? leafCount : 1; // 자식이 없으면 리프 노드로 간주
}

int main() {
    cin >> n;
    int parent;
    
    for (int i = 0; i < n; i++) {
        cin >> parent;
        if (parent == -1) {
            root = i; // 루트 노드 저장
        } else {
            tree[parent].push_back(i); // 부모-자식 관계 설정
        }
    }

    cin >> del;

    if (del == root) { // 루트 삭제 시 트리 전체가 사라짐
        cout << 0 << endl;
        return 0;
    }

    deleteNode(del); // 노드 삭제
    cout << countLeaves(root) << endl; // 리프 노드 개수 출력

    return 0;
}
