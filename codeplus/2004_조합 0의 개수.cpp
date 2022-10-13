#include <iostream>
#include <cmath>
using namespace std;

long long get_two(long long x){
    long long res=0;
    for(long long i=2;i<=x;i*=2){
        res+=x/i;
    }
    return res;
}

long long get_five(long long x){
    long long res=0;
    for(long long i=5;i<=x;i*=5){
        res+=x/i;
    }
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;

    long long a = get_two(n) - get_two(n-m) - get_two(m);
    long long b = get_five(n) - get_five(n-m) - get_five(m);

    cout << min(a, b);
}