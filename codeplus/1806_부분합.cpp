#include <iostream>
#include <cmath>
using namespace std;

int arr[100005];

int main(){
    ios_base::sync_with_stdio(false); 
    cout.tie(0); cin.tie(0);

    int n, s;
    cin >> n >> s;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    int diff=0xffffff;
    int sum=0, lo=1, hi=1;
    while(1){
        if(sum>=s){
            diff=min(diff, hi-lo);
            sum-=arr[lo++];
        }
        else if(hi==n+1) break;
        else sum+=arr[hi++];
    }

    if(diff==0xffffff) cout << 0;
    else cout << diff;
}