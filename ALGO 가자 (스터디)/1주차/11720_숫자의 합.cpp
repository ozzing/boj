#include <iostream>
using namespace std;

int main(){
    int n, tmp, sum=0;
    cin >> n;
    for(int i=0;i<n;i++){
        scanf("%1d", &tmp);
        sum+=tmp;
    }
    cout << sum;
}