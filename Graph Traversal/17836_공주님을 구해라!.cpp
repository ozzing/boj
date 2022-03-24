#include <iostream>
#include <queue>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    char map[101][101];
    bool visited[101][101][2];
    int n, m, t;

    cin >> n >> m >> t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
 
    queue<pair<pair<int,int>,bool>> q;
    
    visited[0][0][0]=true;
    q.push({{0,0}, false});
    
    for(int time=0;time<=t;time++){
        int size=q.size();
        for(int s=0;s<size;s++){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int k=q.front().second;
            q.pop();
            if(x==n-1 && y==m-1){
                cout << time;
                return 0;
            }

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(!visited[nx][ny][1] && (map[nx][ny]=='2'||k==true)){
                    visited[x][y][1]=true;
                    q.push({{nx, ny}, true});
                }
                else{
                    if (!visited[nx][ny][0] && map[nx][ny]=='0') {
                        visited[x][y][0]=true;
                        q.push({{nx, ny}, false});
                    }
                }
            }
        }
    }
    cout << "Fail";
}