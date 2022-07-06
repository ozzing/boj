#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, op, i, x;
    cin >> n >> m;
    vector<int> arr(n+1, 0);
    for(int k=0;k<m;k++){
        cin >> op >> i;
        if(op==1){
            cin >> x;
            arr[i] |= (1 << x);
        }
        else if(op==2){
            cin >> x;
            arr[i] &= ~(1 << x);
        }
        else if(op==3){
            arr[i] = arr[i] << 1;
            arr[i] &= ((1 << 21) - 1);
        }
        else{
            arr[i] = arr[i] >> 1;
            arr[i] &= ~1;
        }
    }

    vector<bool> vec(1 << 21, false);
    int res=0;
    for(int i=1;i<=n;i++){
        if(!vec[arr[i]]) res++;
        vec[arr[i]]=true;
    }

    cout << res;
}