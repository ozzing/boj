#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    vector<int> prime;
    for(int i=0;i<=n;i++){
        arr.push_back(i);
    }
    arr[0]=0;arr[1]=0;

    for(int i=2;i<=sqrt(n);i++){
        if(arr[i]==0) continue;       
        for(int j=2*i;j<=n;j+=i){
            arr[j]=0;
        }
    }

    for(int i=2;i<=n;i++){
        if(arr[i]!=0){
            prime.push_back(arr[i]);
        }
    }

    int start=0, end=0, sum=0, cnt=0;
    while(1){
        if(sum<n){
            sum -= prime[end++];
        }
        else if(start==prime.size()) break;
        else {
            sum += prime[start++];
        }
        if(sum==n) cnt++;
    }
    cout << cnt;
}