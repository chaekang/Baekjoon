#include <iostream>
#include <utility>

using namespace std;

int dr[4] = {0, 1, 0, -1};   // 우 하 좌 상
int dc[4] = {1, 0, -1, 0};

int board[1000][1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, x;
    cin >> N >> x;

    pair<int, int> pos = {-1, -1};

    int center = N / 2;
    int num = 1;

    board[center][center] = num;
    if (x == 1) {
        pos = {center + 1, center + 1};
    }

    int layers = N / 2;
    int startR = center - 1;
    int startC = center - 1;

    for (int i = 1; i <= layers; i++) {
        int r = startR;
        int c = startC;

        for (int d = 0; d < 4;) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (center - i <= nr && nr <= center + i &&
                center - i <= nc && nc <= center + i) {

                num++;
                board[nr][nc] = num;

                if (num == x) {
                    pos = {nr + 1, nc + 1};
                }

                r = nr;
                c = nc;
            } else {
                d++;
            }
        }

        startR--;
        startC--;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }

    cout << pos.first << " " << pos.second << '\n';

    return 0;
}
