#include <iostream>
#include <cmath>
using namespace std;

long long pre[10];

int main(){
    int n;
    cin >> n;

    int digit=1, tmp=n;
    for(int i=0;i<9;i++){
        if(tmp/10>0){
            digit++;
            tmp/=10;
        }
        else break;
    }

    pre[0]=0; pre[1]=9;
    for(int i=2;i<=9;i++){
        pre[i] = i * 9 * pow(10, i-1) + pre[i-1];
    }

    int sum = pre[digit-1];
    if(digit>0) sum += digit * (n - pow(10, digit-1) + 1);
    else sum+= digit * n;

    cout << sum;
}