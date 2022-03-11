#include <iostream>
using namespace std;

long long dp[101];

int main(){
    int t, n;
    cin >> t;

    dp[1]=1; dp[2]=1; dp[3]=1;
    for(int i=4;i<=100;i++){
        dp[i]=dp[i-2]+dp[i-3];
    }

    for(int i=0;i<t;i++){
        cin >> n;
        cout << dp[n] << "\n";
    }
}