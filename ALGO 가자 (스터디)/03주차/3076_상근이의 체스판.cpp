#include <iostream>
using namespace std;

int main(){
    int r, c, a, b;
    cin >> r >> c >> a >> b;
    for (int i=0; i<r*a; i++){
        for(int j=0;j<c*b;j++){
            int val = i/a + j/b;
            if(val%2==0) cout << "X";
            else cout << ".";
        }
        cout << endl;
    }
}