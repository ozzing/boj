#include <iostream>
#include <queue>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char map[105][105];
bool visited[105][105][2];
int n, m, t;

struct block{
    int x;
    int y;
    int k;
    int time;
};
queue<block> q;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    
    visited[0][0][0]=true;
    q.push({0, 0, 0, 0});

    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int k=q.front().k;
        int time=q.front().time;
        q.pop();

        if(map[x][y]=='2') k=1;
        if(x==n-1 && y==m-1){
            if(time<=t) cout << time;
            else cout << "Fail";
            return 0;
        }
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(k==1){
                if(!visited[nx][ny][1]){
                    visited[nx][ny][1]=true;
                    q.push({nx, ny, 1, time+1});
                }
            }
            else{
                if (!visited[nx][ny][0] && map[nx][ny] !='1') {
                    visited[nx][ny][0]=true;
                    q.push({nx, ny, 0, time+1});
                }
            }
        }
    }
    cout << "Fail";
    return 0;
}