#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    while(cin >> n){
        int num=0;
        for(int j=1;j<=n;j++){
            num=num*10+1;
            num%=n;
            if(num==0){
                cout << j << "\n";
                break;
            }
        }
    }
}