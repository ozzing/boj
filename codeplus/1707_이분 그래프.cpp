#include <iostream>
#include <queue>
#include <functional>
using namespace std;

#define MAX 101

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void bfs(){
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0, {1, 1}});
    visited[1][1]=true;

    while(!pq.empty()){
        int wall=pq.top().first;
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        pq.pop();

        if(x==m && y==n){
            cout << wall;
            return;
        }

        for(int d=0;d<4;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];

            if(nx<1 || nx>m || ny<1 || ny>n || visited[nx][ny]) continue;

            if(map[nx][ny]) pq.push({wall+1, {nx, ny}});
            else pq.push({wall, {nx, ny}});
            visited[nx][ny]=true;
        }
    }
}

int main(){
    cin >> n >> m;

    char c;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> c;
            map[i][j]=c-'0';
        }
    }

    bfs();
}