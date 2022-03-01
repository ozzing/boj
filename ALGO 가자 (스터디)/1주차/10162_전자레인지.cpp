#include <iostream>
using namespace std;

int main(){
    int t, a=0, b=0, c=0;
    cin >> t;
    while(t>=300){
        t-=300;
        a++;
    }
    while(t>=60){
        t-=60;
        b++;
    }
    while(t>=10){
        t-=10;
        c++;
    }
    if(t!=0) cout << -1;
    else cout << a << " " << b << " " << c;
}