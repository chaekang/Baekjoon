#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[105][105] = {0,};
int visited[105][105] ={0,};
int N,M;

// bfs
int bfs(){
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    queue<pair<int,int>> q;

    fill(&visited[0][0],&visited[104][105],0);
    visited[0][0] = 1;
    q.push({0,0}); // (0,0)부터 시작
    int count = 0; // 카운팅된 치즈의 개수
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx > N+1 || ny > M+1) continue;
            
            if(map[nx][ny] == 1) {
                visited[nx][ny]++;
                if(visited[nx][ny] >= 2) {
                    map[nx][ny] = 0;
                    count++;
                }
            }
            else if(map[nx][ny] == 0 && !visited[nx][ny]){
                visited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }

    return count;

}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) cin >> map[i][j];

    int count = 0;
    int ans = -1;

    do{
        ans++;
        count = bfs();
    }while(count > 0);

    cout << ans;
}