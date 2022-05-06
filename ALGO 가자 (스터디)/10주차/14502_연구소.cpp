#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int map[9][9];
int temp[9][9];
bool visited[9][9];
int cnt, ans;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};


void bfs(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp[i][j]=map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(temp[i][j]==2){
                queue<pair<int,int>> q;
                visited[i][j]=true;
                q.push({i,j});
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();

                    for(int d=0;d<4;d++){
                        int nx=x+dx[d];
                        int ny=y+dy[d];
                        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                        if(!visited[nx][ny] && temp[nx][ny]==0){
                            visited[nx][ny]=true;
                            temp[nx][ny]=2;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    memset(visited, false, sizeof(visited));

    int safe=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(temp[i][j]==0) safe++;
        }
    }
    if(ans<safe) ans=safe;
}

void wall(){
    if(cnt==3) return bfs();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (map[i][j]==0){
                cnt++;
                map[i][j]=1;
                wall();
                cnt--;
                map[i][j]=0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    cnt=0; ans=-1;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> map[i][j];
            temp[i][j] = map[i][j];
        }
    }

    wall();

    cout << ans;
}