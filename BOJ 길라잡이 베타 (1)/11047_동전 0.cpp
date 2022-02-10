#include <iostream>
#include <algorithm>
using namespace std;

int coin[10];

int main(){
    int flag=-1, count=0;
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> coin[i];
        if(coin[i]<=k) flag = i;
    }
    for(int i=flag;i>=0;i--){
        while(k>=coin[i]){
            k-=coin[i];
            count++;
        }
    }

    cout << count;
}

    