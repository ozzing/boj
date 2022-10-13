#include <iostream>
#include <algorithm>
using namespace std;

int main(){    
    int t, a, b;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> a >> b;
        int big = max(a, b);
        int small = min(a, b);

        int res=big;
        while(res%small!=0){
            res+=big;
        }
        cout << res << "\n";
    }

}