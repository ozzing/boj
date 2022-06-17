#include <iostream>
#include <cstring>
using namespace std;

int w, h;
int map[51][51];
bool visited[51][51];

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void dfs(int x, int y){
    for(int d=0;d<8;d++){
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(!visited[nx][ny] && map[nx][ny]==1) {
            visited[nx][ny]=true;
            dfs(nx, ny);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(1){
        cin >> w >> h;
        if(w==0 && h==0) break;
        
        memset(map, 0, sizeof(map));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
            }
        }

        memset(visited, false, sizeof(visited));
        int cnt=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!visited[i][j] && map[i][j]==1){
                    visited[i][j]=true;
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}