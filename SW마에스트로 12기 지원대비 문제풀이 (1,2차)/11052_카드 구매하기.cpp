#include <iostream>
using namespace std;

int card[1001];
int dp[1001];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> card[i];
    }

    dp[1]=card[1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]=max(dp[i], dp[i-j]+card[j]);
        }
    }

    cout << dp[n];
}