#include <iostream>
#include <cstring>
using namespace std;

int n;
char color[101][101];
bool visited[101][101];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void dfs(int x, int y){
    for(int d=0;d<4;d++){
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(!visited[nx][ny]) {
            if(color[x][y]==color[nx][ny]){
                visited[nx][ny]=true;
                dfs(nx, ny);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> color[i][j];
        }
    }

    int lcnt=0, rcnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                visited[i][j]=true;
                dfs(i, j);
                lcnt++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(color[i][j]=='G') color[i][j]='R';
        }
    }
    memset(visited, false, sizeof(visited));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                visited[i][j]=true;
                dfs(i, j);
                rcnt++;
            }
        }
    }

    cout << lcnt << " " << rcnt << "\n";
}