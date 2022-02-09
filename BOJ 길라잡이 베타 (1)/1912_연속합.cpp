#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> arr;
vector<int> dp;

int main(){
    int n, temp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp;
        arr.push_back(temp);
    }

    dp.push_back(arr[0]);
    for(int i=1;i<n;i++){
            dp.push_back(max(arr[i], dp[i-1]+arr[i]));
    }

    sort(dp.begin(), dp.end(), greater<>());
    cout << dp[0];
}