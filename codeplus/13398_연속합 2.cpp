#include <iostream>
#include <cmath>
using namespace std;

int arr[100002];
int ldp[100002];
int rdp[100002];
int maxi=-1001;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
        ldp[i]=max(ldp[i-1]+arr[i], arr[i]);
        maxi=max(maxi, ldp[i]);
    }
    for(int i=n;i>=1;i--){
        rdp[i]=max(rdp[i+1]+arr[i], arr[i]);
    }

    for(int i=2;i<=n-1;i++){
        maxi=max(maxi, ldp[i-1]+rdp[i+1]);
    }

    cout << maxi;
}