#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long sum=n;
    for(int i=2;i<=n;i++){
        sum+=(n/i)*i;
    }

    cout << sum;

}