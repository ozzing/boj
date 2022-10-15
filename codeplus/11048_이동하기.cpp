#include <iostream>
#include <cmath>
using namespace std;

int map[1001][1001];
int dp[1001][1001];
int n, m;

int dx[3]={-1,0,-1};
int dy[3]={0,-1,-1};

void solve(int x, int y){
    for(int d=0;d<3;d++){
        int nx=x+dx[d];
        int ny=y+dy[d];

        if(nx<0 || nx>n || ny<0 || ny>m) continue;
        dp[x][y]=max(dp[x][y], map[x][y]+dp[nx][ny]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }

    dp[0][0]=map[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            solve(i, j);
        }
    }

    cout << dp[n-1][m-1];
}