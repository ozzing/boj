#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int n, m;
int arr[51][51];
bool visited[51][51];

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int maxi=0;

int bfs(int r, int c){
    queue<pair<pair<int,int>,int>> q;
    q.push({{r,c}, 0});
    visited[r][c]=true;

    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int depth=q.front().second;
        q.pop();

        if(arr[x][y]==1){
            return depth;
        }

        for(int d=0;d<8;d++){
            int nx=x+dx[d];
            int ny=y+dy[d];

            if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny]) continue;
        
            q.push({{nx,ny},depth+1});
            visited[nx][ny]=true;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            memset(visited, false, sizeof(visited));
            int num=bfs(i, j);
            maxi=max(maxi, num);
        }
    }
    cout << maxi << endl;
}