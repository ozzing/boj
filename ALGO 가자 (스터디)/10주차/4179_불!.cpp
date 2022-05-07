#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int>> qj;
queue<pair<int,int>> qf;
int r, c, time;
char map[1001][1001];
int visited[1001][1001][2] = {0,};

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void bfs(){
    while(!qf.empty()){
        int x=qf.front().first;
        int y=qf.front().second;
        qf.pop();

        for(int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
            if(!visited[nx][ny][1] && map[nx][ny]!='#'){
                visited[nx][ny][1]=visited[x][y][1]+1;
                qf.push({nx,ny});
            }
        }
    }

    while(!qj.empty()){
        int x=qj.front().first;
        int y=qj.front().second;
        qj.pop();

        for(int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx<0 || nx>=r || ny<0 || ny>=c){
                cout << visited[x][y][0];
                return;
            } 
            if(!visited[nx][ny][0] && map[nx][ny]!='#'){
                if(!visited[nx][ny][1] || visited[nx][ny][1]>visited[x][y][0]+1){
                    visited[nx][ny][0]=visited[x][y][0]+1;
                    qj.push({nx,ny});
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    time=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> map[i][j];
            if(map[i][j]=='F'){
                qf.push({i,j});
                visited[i][j][1]=1;
            }
            if(map[i][j]=='J'){
                qj.push({i,j});
                visited[i][j][0]=1;
            }
        }
    }
    bfs();
}