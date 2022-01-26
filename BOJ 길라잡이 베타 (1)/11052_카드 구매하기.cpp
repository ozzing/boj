#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int dp[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    cin>> n;
    for(int i=0;i<n;i++){
        cin>> tmp;
        arr.push_back(tmp);
    }

    dp[1]=arr[0];

    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]=max(dp[i], dp[i-j]+arr[j-1]);
        }
    }  

    cout<< dp[n]; 
}