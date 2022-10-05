#include <iostream>
#include <queue>
using namespace std;

#define MAX 201

int n, r1, c1, r2, c2;

struct node{
    int x;
    int y;
    int depth;
};

bool visited[MAX][MAX];

int dx[6]={-2,-2,0,0,2,2};
int dy[6]={-1,1,-2,2,-1,1};

int bfs(){
    queue<node> q;
    node nd;
    nd.x=r1; nd.y=c1; nd.depth=0; 
    q.push(nd);
    visited[r1][c1]=true;

    while(!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int depth=q.front().depth;
        q.pop();

        if(x==r2 && y==c2){
            return depth;
        }
        
        for(int d=0;d<6;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];

            if(nx<0 || nx>=n || ny<0 || ny>=n || visited[nx][ny]) continue;

            node nd={nx, ny, depth+1};
            visited[nx][ny]=true;
            q.push(nd);
        }
    }

    return -1;
}

int main(){
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    cout << bfs();
}