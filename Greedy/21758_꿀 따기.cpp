#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    long long maxi=0;
    long long arr[100000];
    long long sum[100000];

    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(i!=0) sum[i]=arr[i]+sum[i-1];
        else sum[i]=arr[i];
    }

    long long fir=sum[n-1]-arr[0];
    long long sec=sum[n-2];
    long long thi=sum[n-1]-arr[0]-arr[n-1];

    // 벌 벌 통
    for(int i=1;i<n-1;i++){
        long long temp = sum[n-1]-sum[i]-arr[i];
        maxi=max(temp, maxi);
    }
    fir+=maxi;
    maxi=0;

    // 통 벌 벌
    for(int i=1;i<n-1;i++){
        long long temp = sum[i-1]-arr[i];
        maxi=max(temp, maxi);
    }
    sec+=maxi;

    // 벌 통 벌
    int mid=n/2;
    if(n%2==0 && arr[mid] < arr[mid+1]) mid++;
    thi+=arr[mid];

    long long res=max(max(fir,sec),thi);
    cout << res;
}