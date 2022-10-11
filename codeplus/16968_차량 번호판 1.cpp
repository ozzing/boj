#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;

    int res=1;
    bool cc=false, dd=false;
    for(int i=0;i<str.length();i++){
        if(str[i]=='c'){
            if(cc) res*=25;
            if(!cc) res*=26;
            dd=false;
            cc=true;
        }
        if(str[i]=='d'){
            if(dd) res*=9;
            if(!dd) res*=10;
            cc=false;
            dd=true;
        }
    }

    cout << res;
}