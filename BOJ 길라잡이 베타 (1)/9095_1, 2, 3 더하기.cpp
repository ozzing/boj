#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t, k;
    int dp[11]={0};
    dp[1]=1; dp[2]=2; dp[3]=4;
    for(int i=4;i<11;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> k;
        cout<< dp[k] <<"\n";   
    }
}