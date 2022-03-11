#include <iostream>
using namespace std;

#define mod 1000000000
long long dp[101][11]={0,};

int main(){
    int n, sum=0;
    cin >> n;

    for(int i=1;i<10;i++) dp[1][i]=1;
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][1];
        for(int x=1;x<10;x++){
            dp[i][x] = (dp[i-1][x-1]+dp[i-1][x+1]) % mod;
        }
    }
    for(int i=0;i<10;i++){
        sum = (sum+dp[n][i])%mod;
    }

    cout << sum;
}