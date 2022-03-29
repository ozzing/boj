#include <iostream>
using namespace std;

pair<int,int> consult [1500001];
int dp[1500002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, t, p;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> consult[i].first >> consult[i].second;
    }

    for(int i=n;i>=1;i--){
        if(i+consult[i].first<=n+1)
            dp[i]=max(dp[i+1], consult[i].second+dp[i+consult[i].first]);
        else
            dp[i]=dp[i+1];
    }

    cout << dp[1];
}