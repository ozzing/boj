#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int>> q;
int map[102][102];
bool visited[102][102];

int dx[6]={-1,-1,0,0,1,1};
int dy[6]={0,1,-1,1,0,1};
int w, h, cnt;

void bfs(){ 
    visited[0][0]=true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int d=0;d<6;d++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(x%2==0 && (d!=2 && d!=3)) ny-=1;
            if(visited[nx][ny] || nx<0 || nx>w+1 || ny<0 || ny>h+1) continue;

            if(map[nx][ny]==0){
                q.push({nx, ny});
                visited[nx][ny]=true;
            }
            if(map[nx][ny]==1){
                cnt++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> h >> w;
    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            cin >> map[i][j];
        }
    }

    cnt=0;
    q.push({0,0});
    bfs();
    cout << cnt;
}