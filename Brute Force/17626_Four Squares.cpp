#include <iostream>
#include <cmath>
using namespace std;

int dp[50001];
int sqr[224];

int main(){
    int n;
    cin >> n;

    int root = sqrt(n);

    for(int i=0;i<=n;i++) dp[i]=i;
    for(int j=1;j<=root;j++){
        for(int i=1;i<=n;i++){
            if(j*j<=i)
                dp[i]=min(dp[i], dp[i-j*j]+1);                
        }
    }

    cout << dp[n];
}