#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

char mat[21][21];
bool visited[21][21][21][21];
int n, m;

struct node{
    int x1;
    int y1;
    int x2;
    int y2;   
    int depth; 
};

queue<node> q;

bool inside(int x, int y){
    if(x<0||x>=n||y<0||y>=m) return false;
    else return true;
}

void bfs(){
    while(!q.empty()){
        node nd=q.front();
        visited[nd.x1][nd.y1][nd.x2][nd.y2]=true;
        q.pop();
        if(nd.depth>10) break;

        for(int d=0;d<4;d++){
            int nx1=nd.x1+dx[d];
            int ny1=nd.y1+dy[d];
            int nx2=nd.x2+dx[d];
            int ny2=nd.y2+dy[d];
            int depth=nd.depth;
            
            if(!inside(nx1, ny1) && !inside(nx2, ny2)) continue;
            if((inside(nx1, ny1) && !inside(nx2, ny2)) || (!inside(nx1, ny1) && inside(nx2, ny2))){
                if(depth+1>10) cout << -1;
                else cout << depth+1;
                exit(0);
            }

            if(visited[nx1][ny1][nx2][ny2]) continue;
            if(mat[nx1][ny1]=='#' && mat[nx2][ny2]=='#') continue;

            if(mat[nx1][ny1]=='#' ){
                nx1=nd.x1;
                ny1=nd.y1;
            }
            if(mat[nx2][ny2]=='#'){
                nx2=nd.x2;
                ny2=nd.y2;
            }
            visited[nx1][ny1][nx2][ny2]=true;
            q.push({nx1, ny1, nx2, ny2, depth+1});
        }
    }
    cout << -1;
    return;
}

int main(){
    cin >> n >> m;

    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
            if(mat[i][j]=='o') vec.push_back({i,j});
        }
    }

    node nd={vec[0].first, vec[0].second, vec[1].first, vec[1].second, 0};
    visited[vec[0].first][vec[0].second][vec[1].first][vec[1].second]=true;
    q.push(nd);
    bfs();
}