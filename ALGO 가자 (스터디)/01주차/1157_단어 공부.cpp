#include <iostream>
#include <string>
using namespace std;

int alpha[26] = {0,};

int main(){
    string str;
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(str[i]>=97) str[i]-=32;
        alpha[str[i]-65]++;
    }

    int max=0, cnt=0, flag=0;
    for(int i=0;i<26;i++){
        if(alpha[i]>max){
            max=alpha[i];
            cnt=0;
            flag=i;
        }
        else if(alpha[i]==max) cnt++;
    }
    if(cnt) cout << "?";
    else cout << (char)('A'+flag);
}