#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, sum=0;
    int hund, ten, one;
    cin >> n;
    for(int i=1;i<=n;i++){
        if(i<100) sum++;
        else{
            hund=i/100;
            ten=i%100/10;
            one=i%10;
            if(hund-ten==ten-one) sum++;
        }
    }
    cout << sum;
}