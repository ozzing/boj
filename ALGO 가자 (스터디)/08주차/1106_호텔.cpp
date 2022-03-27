#include <iostream>
using namespace std;

int dp[100001];

int main(){
    int c, n, money, custo;
    cin >> c >> n;
    for(int i=1;i<=n;i++){
        cin >> money >> custo;
        for(int j=1;j<=100001;j++){
            if(j>=money) dp[j]=max(dp[j], dp[j-money]+custo);
        }
    }
    for(int i=1;i<=100001;i++){
        if(dp[i]>=c) {
            cout << i;
            break;
        }
    }
}