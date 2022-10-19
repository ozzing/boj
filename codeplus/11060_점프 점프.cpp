#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        dp[i]=0xffff;
    }

    dp[1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=arr[i];j++){
            dp[i+j]=min(dp[i+j], dp[i]+1);
        }
    }

    if(dp[n]==0xffff) cout << -1;
    else cout << dp[n];

}