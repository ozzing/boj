#include <iostream>
using namespace std;

#define MOD 1000000009
#define MAX 100000

long long dp[100001][3]={0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    dp[1][0]=1; dp[2][1]=1; 
    dp[3][0]=1; dp[3][1]=1; dp[3][2]=1;

    for(int j=4;j<=MAX;j++){
        dp[j][0]=(dp[j-1][1]+dp[j-1][2]) % MOD;
        dp[j][1]=(dp[j-2][0]+dp[j-2][2]) % MOD;
        dp[j][2]=(dp[j-3][0]+dp[j-3][1]) % MOD;
    }

    int t, n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> n;
        cout << ((long long)dp[n][0] + dp[n][1] + dp[n][2]) % MOD << "\n";
    }
}