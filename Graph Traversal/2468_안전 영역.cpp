#include <iostream>
#include <cstring>
using namespace std;

int n, depth;
int map[101][101];
bool visited[101][101];
int temp[101][101];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void dfs(int x, int y){
    visited[x][y]=true;

    for(int d=0;d<4;d++){
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        if(!visited[nx][ny]) {
            if(temp[x][y]!=-1){
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int high=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j]>high) high=map[i][j];
        }
    }

    int max=1;
    for(int d=1;d<=high;d++){
        depth=d;
        int cnt=0;
        memset(visited, false, sizeof(visited));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j]=map[i][j];
                if(temp[i][j]<=depth) temp[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && temp[i][j]!=-1){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        if(cnt>max) max=cnt;
    }

    cout << max;
}