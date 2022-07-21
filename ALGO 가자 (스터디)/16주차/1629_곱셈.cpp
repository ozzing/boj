#include <iostream>
using namespace std;

long a, b, c;

long long int solve(long long int x){
    if(x==1) return a%c;

    long long int y = solve(x/2)%c;
    if(x%2) return y%c * y%c * a%c;
    else return y%c * y%c;
}

int main(){    
    cin >> a >> b >> c;

    cout << solve(b);
}