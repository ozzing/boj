#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, num;
    cin >> n >> m;
    if(n>m){
        int temp=m; m=n; n=temp;
    }
    for(int i=n;i>=1;i--){
        if(n%i==0 && m%i==0){
            num=i;
            printf("%d\n", num);
            break;
        }
    }
    printf("%d\n", num * (m/num) * (n/num));
}