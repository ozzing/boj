#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, m, n, x, y;
    cin >> t;

    for(int i=0;i<t;i++){
        cin >> m >> n >> x >> y;

        int pivot, maxi, mini;
        if(m>n){
            pivot=x;
            maxi=m;
            mini=n;
        }
        else{
            pivot=y;
            maxi=n;
            mini=m;
        }
        int cnt=0;
        while(1){
            if(cnt>mini){
                cout << "-1\n";
                break;
            }
            if((pivot-x)%m==0 && (pivot-y)%n==0){
                cout << pivot << "\n";
                break;
            }
            pivot+=maxi;
            cnt++;
        }
    }
}