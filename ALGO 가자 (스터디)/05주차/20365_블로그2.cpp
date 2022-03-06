#include <iostream>
using namespace std;

int main(){
    int n, b=0, r=0;
    bool bflag=false;
    char c;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> c;
        if((i==0 || !bflag) && c=='B'){
            b++;
            bflag=true;
        }
        if((i==0 || bflag) && c=='R'){
            r++;
            bflag=false;
        }
    }

    if(b>r) cout << r+1 << "\n";
    else cout << b+1 << "\n";
}