#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;
    int sum=0;
    for(int i=0;i<str.length();i++){
        int num = str[i];
        if(num>=65&&num<=90){
            sum+=num-38;
        }
        if(num>=97&&num<=122){
            sum+=num-96;
        }
    }

    bool check=true;
    for(int i=2;i<sum;i++){
        if(sum%i==0){
            check=false;
        }
    }
    if(check || sum==1) cout << "It is a prime word.\n";
    else cout << "It is not a prime word.\n";
}