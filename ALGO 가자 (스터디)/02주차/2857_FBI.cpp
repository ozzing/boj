#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    bool check=false;
    for(int i=1;i<=5;i++){
        cin >> str;
        int idx = str.find("FBI");
        if(idx>=0 && idx<str.length()) {
            cout << i << " ";
            check=true;
        }
    }
    if(!check) cout << "HE GOT AWAY!";
}