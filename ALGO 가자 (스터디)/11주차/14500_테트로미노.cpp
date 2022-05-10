#include <iostream>
using namespace std;

int map[501][501];
bool visited[501][501];
int res;
int n, m;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void dfs(int sum, int x, int y, int depth){
    if(depth==4){
        res=max(res, sum);
        return;
    }

    for(int d=0;d<4;d++){
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
        if(!visited[nx][ny]){
            visited[nx][ny]=true;
            dfs(sum+map[nx][ny], nx, ny, depth+1);
            visited[nx][ny]=false;
        }
    }

    int up=map[x-1][y];
    int down=map[x+1][y];
    int left=map[x][y-1];
    int right=map[x][y+1];
    // ㅗ
    if(x-1>=0 && y-1>=0 && y+1<m){
        res=max(res, (map[x][y] + up + left + right));
    }
    // ㅓ
    if(x-1>=0 && y-1>=0 && x+1<n){
        res=max(res, (map[x][y] + up + left + down));
    }
    // ㅜ
    if(y-1>=0 && y+1<m && x+1<n){
        res=max(res, (map[x][y] + left + right + down));
    }
    // ㅏ
    if(x-1>=0 && y+1<m && x+1<n){
        res=max(res, (map[x][y] + up + right + down));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    res=-1;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j]; 
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=true;
            dfs(0, i, j, 0);
            visited[i][j]=false;
        }
    }
    cout << res;
}