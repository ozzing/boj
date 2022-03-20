#include <iostream>
using namespace std;

int dp[101][100001];

int main(){
    int sum=0;
    int n, k, w, v;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> w >> v;
        for(int j=1;j<=k;j++){
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
            if(j>=w) dp[i][j]=max(dp[i][j], dp[i-1][j-w]+v);
            sum = max(sum, dp[i][j]);
        }
    }
    cout << sum;
}