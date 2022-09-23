#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int m;
    cin >> m;

    string op;
    int x;
    int bit=0;
    for(int i=0;i<m;i++){
        cin >> op;
        if(op=="all"){ bit=(1<<21)-1; continue; }
        if(op=="empty"){ bit=0; continue; }

        cin >> x;
        if(op=="add") bit |= (1<<x);
        if(op=="remove") bit &= ~(1<<x);
        if(op=="check") {
            if(bit & (1<<x)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        if(op=="toggle") bit ^= (1<<x);
    }
}