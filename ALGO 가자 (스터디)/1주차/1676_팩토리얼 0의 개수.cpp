#include <iostream>
using namespace std;

int main(){
    long long fac=1;
    int n, sum=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        int cnt=0;
        int tmp=i;
        while(1){
            if(tmp%5==0){
                cnt++;
                tmp/=5;
            }
            else break;
        }
        sum+=cnt;
    }
    cout << sum;
}