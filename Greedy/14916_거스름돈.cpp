#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n==1 || n==3){
        cout << -1;
        return 0;
    }

    int cnt=0;
    while(n%5!=0){
        n-=2;
        cnt++;
    }
    cnt+=n/5;
    cout << cnt;
}