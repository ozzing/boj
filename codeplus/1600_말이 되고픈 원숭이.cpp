#include <iostream>
#include <queue>
using namespace std;

int k, w, h;
int mat[201][201];
bool visited[201][201][31];

struct node{
    int x;
    int y;
    int depth;
    int jump;
};

int dx[12]={-1,0,1,0,-1,-2,-2,-1,1,2,2,1};
int dy[12]={0,-1,0,1,-2,-1,1,2,2,1,-1,-2};

void bfs(){
    queue<node> q;
    node move={0,0,0,0};
    q.push(move);
    visited[0][0][0]=true;

    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int depth=q.front().depth;
        int jump=q.front().jump;
        q.pop();

        if(x==h-1 && y==w-1){
            cout << depth;
            return;
        }

        for(int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];

            if(nx<0 || nx>=h || ny<0 || ny>=w || visited[nx][ny][jump]) continue;
            if(mat[nx][ny]==1) continue;

            node move={nx, ny, depth+1, jump};
            visited[nx][ny][jump]=true;
            q.push(move);
        }

        if(jump>=k) continue;

        for(int d=4;d<12;d++){
             int nx=x+dx[d];
            int ny=y+dy[d];

            if(nx<0 || nx>=h || ny<0 || ny>=w || visited[nx][ny][jump+1]) continue;
            if(mat[nx][ny]==1) continue;
            
            node move={nx, ny, depth+1, jump+1};
            visited[nx][ny][jump+1]=true;
            q.push(move);
        }
    }

    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k >> w >> h;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> mat[i][j];
        }
    }

    bfs();    
}