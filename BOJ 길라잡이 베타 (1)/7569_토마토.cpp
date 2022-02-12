#include <iostream>
#include <queue>
using namespace std;

queue<pair<pair<int,int>,int>> q;
int box[100][100][100];
int visited[100][100][100] = {0,};
int m, n, h;

int dx[6]={0,0,0,-1,0,1};
int dy[6]={0,0,-1,0,1,0};
int dz[6]={-1,1,0,0,0,0};

void bfs(){
    while(!q.empty()){
        int prex = q.front().first.first;
        int prey = q.front().first.second;
        int prez = q.front().second;
        q.pop();

        for(int i=0;i<6;i++){
            int x = prex + dx[i];
            int y = prey + dy[i];
            int z = prez + dz[i];
            
            if(x>=0&&x<n&&y>=0&&y<m&&z>=0&&z<h&&box[x][y][z]==0&&!visited[x][y][z]){
                visited[x][y][z] = visited[prex][prey][prez]+1;
                q.push({{x,y}, z});
            }
        }
    }
}

int main(){
    cin >> m >> n >> h;
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1){
                    visited[i][j][k] = 1;
                    q.push({{i,j},k});
                }
                if(box[i][j][k] == -1){
                    visited[i][j][k]= -1;
                }
            }
        }
    }

    bfs();

    bool check=true;
    int max = 0;
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j][k]>max) max = visited[i][j][k];
                if(visited[i][j][k]==0) check=false;
            }
        }
    }

    if(check) cout << max-1;
    else cout << -1;
}