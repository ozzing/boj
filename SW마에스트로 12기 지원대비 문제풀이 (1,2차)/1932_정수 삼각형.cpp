#include <iostream>
using namespace std;

int main(){
    int tri[501][501];
    int dp[501][501];
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin >> tri[i][j];
        }
    }
    dp[1][1]=tri[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1) dp[i][j]=dp[i-1][j]+tri[i][j];
            else if(j==n) dp[i][j]=dp[i-1][j-1]+tri[i][j];
            else{
                dp[i][j]=tri[i][j];
                dp[i][j]+=max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }

    int maxi=0;
    for(int j=1;j<=n;j++){
        maxi=max(maxi, dp[n][j]);
    }
    cout << maxi;
}