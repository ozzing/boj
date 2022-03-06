#include <iostream>
using namespace std;

int stair[301];
int dp[301];

int main(){
    int n, tmp;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> stair[i];
    }

    dp[0]=0; dp[1]=stair[1]; dp[2]=dp[1]+stair[2];
    for(int i=3;i<=n;i++){
        dp[i]=max(dp[i-2]+stair[i], dp[i-3]+stair[i-1]+stair[i]);
    }
    cout << dp[n];
}