#include <iostream>
using namespace std;

int dp[1001];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+1;
        if(i<=n-3) min(dp[i], dp[i-3]+1);
    }
    if(dp[n]%2==1) cout << "SK";
    else cout << "CY";
}