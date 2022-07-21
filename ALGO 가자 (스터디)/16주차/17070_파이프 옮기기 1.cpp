#include <iostream>
using namespace std;

int map[17][17];
int dp[17][17][3]={0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
        }
    }

    dp[1][2][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1 || i==1&&j==2 || map[i][j]==1) continue;
            dp[i][j][0]=dp[i][j-1][0]+dp[i][j-1][1];
            if(map[i-1][j]==0 && map[i][j-1]==0) dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
            dp[i][j][2]=dp[i-1][j][1]+dp[i-1][j][2];
        }
    }

    cout << dp[n][n][0]+dp[n][n][1]+dp[n][n][2];
}