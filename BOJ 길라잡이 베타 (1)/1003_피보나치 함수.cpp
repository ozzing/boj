#include <iostream>
#include <algorithm>
using namespace std;

int zero, one;

void fibo(int n){
    if(n==0){
        zero=1, one=0; return;
    }
    
    zero=0, one=1; 
    if(n==1){
        return;
    }
    
    for(int i=2;i<=n;i++){
        int temp=one;
        one+=zero;
        zero=temp;
    }
}

int main(){
    int t, n;
    cin >> t;
    for(int i=0;i<t;i++){
        zero=0, one=0;
        cin >> n;
        fibo(n);
        printf("%d %d\n", zero, one);
    }
}