#include <iostream>
#include <cmath>
using namespace std;

int n;
int p[1001];
int dp[1001];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i];
    }

    for(int i=1;i<=n;i++){
        dp[i]=p[i];
        for(int j=1;j<i;j++){
            dp[i]=min(dp[i], dp[i-j]+p[j]);
        }
    }

    cout << dp[n];
}