#include <iostream>
using namespace std;

int num[101];
long long dp[101][21] = {0,};

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    dp[0][num[0]]=1;
    for(int i=1;i<n-1;++i){
        for(int j=0;j<=20;++j){
            if(dp[i-1][j]>0){
                if(j+num[i]<=20) dp[i][j+num[i]]+=dp[i-1][j];
                if(j-num[i]>=0) dp[i][j-num[i]]+=dp[i-1][j];
            }
        }
    }

    cout << dp[n-2][num[n-1]];
}