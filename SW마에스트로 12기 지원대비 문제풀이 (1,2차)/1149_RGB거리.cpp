#include <iostream>
using namespace std;

int dp[1001][3];
int rgb[1001][3];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2]; 
    }
    for(int i=0;i<3;i++) dp[1][i] = rgb[1][i];
    for(int i=2;i<=n;i++){
        dp[i][1]=min(dp[i-1][0], dp[i-1][2]) + rgb[i][1];
        dp[i][2]=min(dp[i-1][0], dp[i-1][1]) + rgb[i][2];        
        dp[i][0]=min(dp[i-1][1], dp[i-1][2]) + rgb[i][0];
    }

    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);
}