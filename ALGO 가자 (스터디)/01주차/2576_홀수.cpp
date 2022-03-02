#include <iostream>
using namespace std;

int main(){
    int tmp, sum=0, min=100;
    for(int i=0;i<7;i++){
        cin >> tmp;
        if(tmp%2==1){
            sum+=tmp;
            if(min>tmp) min=tmp;
        }
    }
    if(sum) cout << sum << "\n" << min;
    else cout << -1;
}