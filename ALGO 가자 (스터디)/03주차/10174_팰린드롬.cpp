#include <iostream>
#include <string>
using namespace std;

int main(){
    string str, tmp;
    int n;
    cin >> n;
    getchar();
    for(int t=0;t<n;t++){
        tmp="";
        getline(cin, str);
        for(int i=0;i<str.length();i++){
            if(str[i]>=65&&str[i]<=90){
                str[i]+=32;
            }
        }

        bool check=true;
        for(int i=0;i<str.length()/2;i++){
            if(str[i]!=str[str.length()-1-i]) check=false;
        }
        if(check) cout << "Yes\n";
        else cout << "No\n";
    }
}