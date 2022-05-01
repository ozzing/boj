#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int,int>> q;
int t, h, w, cnt;
char map[105][105];
bool visited[105][105];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
            if(!visited[nx][ny] && map[nx][ny]=='#'){
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for(int c=0;c<t;c++){
        cin >> h >> w;
        cnt=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin >> map[i][j];
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!visited[i][j] && map[i][j]=='#'){
                    q.push({i,j});
                    visited[i][j]=true;
                    bfs();
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        memset(visited, false, sizeof(visited));
    }
}