#include <iostream>
using namespace std;

#define MAX 5002

int num[MAX];
int dp[MAX][MAX];

int solve(int start, int end){
    if(start>=end) return 0;
    if(dp[start][end]!=0) return dp[start][end];

    if(num[start]!=num[end]){
        dp[start][end] = min(solve(start+1, end), solve(start, end-1))+1;
    }
    else{
        dp[start][end] = solve(start+1, end-1);
    }
    
    return dp[start][end];
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }

    cout << solve(0, n-1);
}