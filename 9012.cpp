#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n, check;
    string str;
    cin >> n;
    for(int i=0;i<n;i++){
        stack<char> vps;
        cin>> str;
        check=1;
        for(int j=0;j<str.length();j++){
            if(str[j]=='('){
                vps.push(str[j]);
            }  
            else if (str[j]==')'){
                if(vps.empty()){
                    check=0;
                }
                else vps.pop();
            }
        }
        if(check==1 && vps.size()==0) cout<< "YES\n";
        else cout<< "NO\n";
    }
}