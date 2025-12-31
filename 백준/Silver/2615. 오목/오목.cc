#include <iostream>
using namespace std;

int board[19][19];

// →, ↓, ↘, ↗
int dx[4] = {0, 1, 1, -1};
int dy[4] = {1, 0, 1, 1};

bool in(int x, int y) {
    return x >= 0 && x < 19 && y >= 0 && y < 19;
}

int main() {
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++)
            cin >> board[i][j];

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (board[i][j] == 0) continue;

            int color = board[i][j];

            for (int d = 0; d < 4; d++) {

                // 시작점 체크 (반대 방향)
                int bx = i - dx[d];
                int by = j - dy[d];
                if (in(bx, by) && board[bx][by] == color)
                    continue;

                int cnt = 1;
                int x = i;
                int y = j;

                while (true) {
                    x += dx[d];
                    y += dy[d];
                    if (!in(x, y) || board[x][y] != color)
                        break;
                    cnt++;
                }

                if (cnt == 5) {
                    cout << color << "\n";
                    cout << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << 0 << "\n";
}
