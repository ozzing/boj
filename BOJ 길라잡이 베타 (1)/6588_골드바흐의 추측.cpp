#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool is_prime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    bool check=false;
    while(1){
        cin >> n;
        if(n==0) break;
        for(int i=1;i<n/2;i++){
            int tmp = 2*i+1;
            if(is_prime(tmp) && is_prime(n-tmp)){
                printf("%d = %d + %d\n", n, a, b);
                check=true;
                break;
            }
        }
        if(!check){
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
}