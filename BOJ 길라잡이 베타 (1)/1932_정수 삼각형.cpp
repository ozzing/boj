#include <iostream>
using namespace std;

int dp[501][501];

int main(){
    int n, temp;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin >> temp;
            dp[i][j]=temp;
        }
    }

    for(int i=n-1;i>0;i--){
        for(int j=0;j<n;j++){
            if(dp[i][j]<dp[i][j+1]){
                dp[i-1][j]+=dp[i][j+1];
            }
            else{
                dp[i-1][j]+=dp[i][j];
            }
        }
    }

    cout << dp[0][0];
}