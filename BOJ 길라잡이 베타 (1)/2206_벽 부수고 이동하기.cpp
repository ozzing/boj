#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<int, int>, int>> q;
int n, m;
int map[1000][1000];
int visited[1000][1000][2] = { 0, };

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

int bfs() {
    visited[0][0][0] = 1;
    q.push({ { 0,0 } ,0 });
    while (!q.empty()) {
        int prex = q.front().first.first;
        int prey = q.front().first.second;
        int wall = q.front().second;
        q.pop();

        if (prex == n - 1 && prey == m - 1) return visited[prex][prey][wall];

        for (int i = 0; i < 4; i++) {
            int x = prex + dx[i];
            int y = prey + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && map[x][y] == 0 && !visited[x][y][wall]) {
                visited[x][y][wall] = visited[prex][prey][wall] + 1;
                q.push({ { x,y }, wall });
            }
            else if (x >= 0 && x < n && y >= 0 && y < m && map[x][y] == 1 && !wall) {
                visited[x][y][wall + 1] = visited[prex][prey][wall] + 1;
                q.push({ { x,y },wall + 1 });
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    cout << bfs();
}