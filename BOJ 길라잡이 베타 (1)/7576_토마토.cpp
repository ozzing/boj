#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int box[1000][1000];
int visited[1000][1000] = {0,};
int m, n;

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

void bfs(){
    while(!q.empty()){
        int prex = q.front().first;
        int prey = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int x = prex + dx[i];
            int y = prey + dy[i];
            
            if(x>=0&&x<n&&y>=0&&y<m&&box[x][y]==0&&!visited[x][y]){
                visited[x][y]=visited[prex][prey]+1;
                q.push({x,y});

            }
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> box[i][j];
            if(box[i][j]==1){
                q.push({i,j});
                visited[i][j]=1;
            }
            else if (box[i][j]==-1)
                visited[i][j]=-1;
        }
    }
    
    bfs();

    bool check=true;
    int max = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]>max) max = visited[i][j];
            if(visited[i][j]==0) check=false;
        }
    }

    if(check) cout << max-1;
    else cout << -1;
}