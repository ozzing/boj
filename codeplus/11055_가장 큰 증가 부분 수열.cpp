#include <iostream>
#include <cmath>
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
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        dp[i]=arr[i];
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j])
                dp[i]=max(dp[i], dp[j]+arr[i]);
        }
        ans=max(ans, dp[i]);
    }
    cout << ans;
}