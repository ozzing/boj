#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    double f;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> f;
        f*=80;
        round(f);
        f/=100;
        printf("$%.02lf\n", f);
    }
}