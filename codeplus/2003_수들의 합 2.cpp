#include <iostream>
using namespace std;

int arr[10001];
int dp[10001];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        dp[i]=dp[i-1]+arr[i];
    }

    int cnt=0;
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(dp[j]-dp[i]==m) cnt++;
        }
    }
    
    cout << cnt;
}