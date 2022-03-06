#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int cnt=1;

    while(1){
        if(b%10==1){
            cnt++;
            b/=10;
        }
        else if(b%2==0){
            cnt++;
            b/=2;
        }
        else if(b%2!=0){
            break;
        }

        if(a==b) break;
        else if (a>b) break;
    }

    if(a==b) cout << cnt;
    else cout << -1;
}