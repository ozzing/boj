#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dp[101][51];

string stradd(string str1, string str2){
    string res;
    int sum=0;
    while(!str1.empty() || !str2.empty() || sum){
        if (!str1.empty()){
            sum += str1.back() - '0';
            str1.pop_back();
        }
        if (!str2.empty()){
            sum += str2.back() - '0';
            str2.pop_back();
        }
        res.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;

    if(m>n/2) m=n-m;
    for(int i=0;i<=n;i++) {dp[i][0]='1'; dp[i][1]=to_string(i);}
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp[i][j] = stradd(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    cout << dp[n][m];
}