#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[100][100];
bool visited[100][100] = { false, };
int cnt[100][100] = { 0, };

int xx[4] = { 0, 1, 0, -1 };
int yy[4] = { -1, 0, 1, 0 };

void bfs() {
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visited[0][0] = true;
    cnt[0][0] = 1;

    while (!q.empty()) {
        int prex = q.front().first;
        int prey = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = prex + xx[i];
            int y = prey + yy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && map[x][y] == 1 && !visited[x][y]) {
                q.push({ x,y });
                visited[x][y] = true;
                cnt[x][y] = cnt[prex][prey] + 1;
            }
        }
    }

    cout << cnt[n - 1][m - 1];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    bfs();
}