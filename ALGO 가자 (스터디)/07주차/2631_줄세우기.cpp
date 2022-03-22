#include <iostream>
#include <algorithm>
using namespace std;

int child[200];
int dp[200] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> child[i];
    }

    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(child[i]>child[j] && dp[i]<=dp[j]) dp[i]++;
        }
    }

    int res=0;
    for(int i=0;i<n;i++){
        res=max(res, dp[i]);
    }
    cout << n-res;
}

