#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> drink;
vector<int> dp;

int main(){
    int n, temp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>> temp;
        drink.push_back(temp);
    }

    dp.push_back(drink[0]);
    dp.push_back(drink[0]+drink[1]);
    dp.push_back(max(max(drink[0], drink[1])+drink[2], dp[1]));
    for(int i=3;i<n;i++){
        dp.push_back(max(max(dp[i-3]+drink[i-1], dp[i-2])+drink[i], dp[i-1]));
    }
    sort(dp.begin(), dp.end(), greater<>());
    cout << dp[0];
}
