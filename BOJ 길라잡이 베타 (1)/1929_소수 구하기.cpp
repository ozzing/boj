#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    vector<int> arr;
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
    
    for(int i=m;i<=n;i++){
        if(arr[i]!=0)
            printf("%d\n", i);
    }
}