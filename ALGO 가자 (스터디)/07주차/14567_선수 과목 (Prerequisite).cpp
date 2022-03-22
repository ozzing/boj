#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> subj[500000];
int dp[1001];

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> subj[i].first >> subj[i].second;
    }

    sort(subj, subj+m);
    for(int i=1;i<=n;i++) dp[i]=1;
    for(int i=0;i<m;i++){
        dp[subj[i].second] = max(dp[subj[i].second], dp[subj[i].first]+1);
    }

    for(int i=1;i<=n;i++) cout << dp[i] << " ";
}