#include <iostream>
using namespace std;

int map[51][51];
int visited[51][51];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void dfs(int x, int y){
    visited[x][y]=1;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(!visited[nx][ny]&&map[nx][ny]){
            dfs(nx, ny);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t, m, n, k, x, y, cnt=0;
    cin >> t;
    for(int z=0;z<t;z++){
        cin >> m >> n >> k;
        cnt=0;
        for(int i=0;i<k;i++){
            cin >> x >> y;
            map[x][y]=1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&map[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                map[i][j]=0;
                visited[i][j]=0;
            }
        }
    }
}