#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string n;
    cin >> n;
    if(n=="0"){
        cout << 0;
        return 0;
    }

    string res;
    for(int i=0;i<n.length();i++){
        int tmp = n[i] - '0';

        res+=to_string(tmp/4);
        res+=to_string(tmp%4/2);
        res+=to_string(tmp%4%2/1);
    }

    int start=0;
    for(int i=0;i<res.length();i++){
        if(res[i]=='1'){
            start=i;
            break;
        }
    }

    cout << res.substr(start, res.length()-start);
}