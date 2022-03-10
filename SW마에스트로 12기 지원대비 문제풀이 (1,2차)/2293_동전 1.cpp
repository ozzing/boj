#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int dp[10001];

int main(){
    int n, k, tmp;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());

    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=vec[i];j<=k;j++){
            dp[j]+=dp[j-vec[i]];
        }
    }

    cout << dp[k];
}