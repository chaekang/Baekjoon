#include <iostream>
using namespace std;

int dice[6] = { 0, };
int dx[4] = { 0, 0, -1, 1 }; // 동, 서, 북, 남
int dy[4] = { 1, -1, 0, 0 };

void Turn(int dir) {
    int temp[6];
    for (int i = 0; i < 6; i++) temp[i] = dice[i];

    if (dir == 1) { // 동
        dice[0] = temp[3];
        dice[2] = temp[0];
        dice[5] = temp[2];
        dice[3] = temp[5];
    }
    else if (dir == 2) { // 서
        dice[0] = temp[2];
        dice[3] = temp[0];
        dice[5] = temp[3];
        dice[2] = temp[5];
    }
    else if (dir == 3) { // 북
        dice[0] = temp[4];
        dice[1] = temp[0];
        dice[5] = temp[1];
        dice[4] = temp[5];
    }
    else if (dir == 4) { // 남
        dice[0] = temp[1];
        dice[4] = temp[0];
        dice[5] = temp[4];
        dice[1] = temp[5];
    }
}

int main() {
    int n, m, x, y, k;
    int map[20][20];

    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int i = 0; i < k; i++) {
        int dir;
        cin >> dir;

        int nx = x + dx[dir - 1];
        int ny = y + dy[dir - 1];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;

        Turn(dir);

        if (map[nx][ny] == 0) {
            map[nx][ny] = dice[5];
        }
        else {
            dice[5] = map[nx][ny];
            map[nx][ny] = 0;
        }

        x = nx;
        y = ny;

        cout << dice[0] << '\n';
    }

    return 0;
}
