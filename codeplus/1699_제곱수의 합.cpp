#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100000
int dp[MAX+1];

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=MAX;i++){
        dp[i]=9999;
        for(int j=1;j<=sqrt(i);j++){
            dp[i]=min(dp[i], dp[i-j*j]+1);
        }
    }
    cout << dp[n];
}