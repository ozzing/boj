#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    bool check=false;
    int val=0, two=1;
    string str, ans="";
    cin >> str;
    for(int i=str.size()-1;i>=0;i--){
        if(str[i]=='1') {
            val+=two;
            check=true;
        }
        two*=2;
        if(two==8){
            ans+=to_string(val);
            two=1;
            val=0;
        }
    }
    if(val==0 && check){}
    else ans+=to_string(val);
    reverse(ans.begin(), ans.end());
    cout << ans;
}