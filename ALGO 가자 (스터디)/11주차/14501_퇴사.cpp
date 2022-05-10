#include <iostream>
using namespace std;

pair<int,int> day[16];
int dp[16];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> day[i].first >> day[i].second;
    }

    for(int i=n;i>=1;i--){
        if(i+day[i].first<=n+1)
            dp[i]=max(dp[i+1], dp[i+day[i].first]+day[i].second);
        else
            dp[i]=dp[i+1];
    }

    cout << dp[1];
}