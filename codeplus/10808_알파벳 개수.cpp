#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;

    for(int i=0;i<26;i++){
        int cnt=0;
        for(int j=0;j<str.length();j++){
            if(str[j]=='a'+i) cnt++;
        }
        cout << cnt << " ";
    }
} 