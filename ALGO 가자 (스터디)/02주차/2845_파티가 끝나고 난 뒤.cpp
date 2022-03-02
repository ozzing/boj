#include <iostream>
using namespace std;

int main(){
    int l, p, total, tmp;
    cin >> l >> p;
    total = l * p;
    for(int i=0;i<5;i++){
        cin >> tmp;
        cout << tmp-total << " ";
    }
}