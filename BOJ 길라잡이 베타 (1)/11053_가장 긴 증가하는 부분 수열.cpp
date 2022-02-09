#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000];
int dp[1000];
int res = 0;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j])
                dp[i]=max(dp[i], dp[j]+1);
        }
        res=max(res, dp[i]);
    }
    cout << res;
}