#include <iostream>
using namespace std;

int main(){
    long long t, a, b;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> a >> b;
        cout << (a*a)/(b*b) << "\n";
    }
}