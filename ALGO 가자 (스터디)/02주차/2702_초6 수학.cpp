#include <iostream>
using namespace std;

int main(){
    int t, a, b, gcd, lcm;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> a >> b;
        if(a>b){
            int temp=a; a=b; b=temp;
        }
        for(int j=b;j>=0;j--){
            if(a%j==0&&b%j==0){
                gcd = j;
                break;
            }
        }
        lcm = gcd * (a/gcd) * (b/gcd);
        cout << lcm << " " << gcd << endl;
    }
}