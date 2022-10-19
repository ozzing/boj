#include <iostream>
using namespace std;

int coin[105];
int arr[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i=1;i<=k;i++){
        arr[i]=0xffff;
    }
    for(int i=0;i<n;i++){
        cin >> coin[i];
        arr[coin[i]]=1;
    }

    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i+coin[j]>k) continue;
            arr[i+coin[j]]=min(arr[i+coin[j]], arr[i]+1);
        }
    }

    if(arr[k]==0xffff) cout << -1;
    else cout << arr[k];
}