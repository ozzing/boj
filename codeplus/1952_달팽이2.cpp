#include <iostream>
using namespace std;

bool visited[101][101];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main(){
    int n, m;
    cin >> m >> n;

    int x=1, y=1, cnt=0, ans=0, d=0;
    visited[1][1]=true;
    while(1){
        if(cnt==m*n) break;

        int nx=x+dx[d];
        int ny=y+dy[d];

        if(nx<1 || nx>m || ny<1 || ny>n || visited[nx][ny]){
            d=(d+1)%4;
            nx=x+dx[d];
            ny=y+dy[d];
            ans++;
        }
        visited[nx][ny]=true;
        x=nx; y=ny;
        cnt++;
    }
    cout << ans-1;
}