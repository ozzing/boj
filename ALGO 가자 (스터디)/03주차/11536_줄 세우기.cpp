#include <iostream>
#include <string>
using namespace std;

int main(){
    string pre, str;
    bool inc=true, dec=true;
    int n;
    cin >> n;
    cin >> pre;
    for(int i=1;i<n;i++){
        cin >> str;
        if(pre.compare(str)>0) inc=false;
        if(pre.compare(str)<0) dec=false;
        pre=str;
    }

    if(!inc&&!dec) cout << "NEITHER\n";
    else if(!dec) cout << "INCREASING\n";
    else if(!inc) cout << "DECREASING\n";
}