#include <iostream>
using namespace std;
#define MAX 1000001

long long dp[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long sum=0;
    int t, n;
    cin >> t;
    
    for(int i=1;i<MAX;i++){
        for(int j=i;j<MAX;j+=i){
            dp[j]+=i;
        }
    }

    for(int i=2;i<MAX;i++){
        dp[i]+=dp[i-1];
    }

    for(int i=0;i<t;i++){
        cin >> n;
        cout << dp[n] << "\n";
    }

}