#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int t, cnt, p;
    cin >> t;
    getchar();
    for(int i=0;i<t;i++){
        bool flag=false;
        p=1;
        cin >> str;
        cnt=0;
        for(int j=0;j<str.length();j++){
            if(str[j]=='O'){
                if(flag==true) p+=1;
                cnt+=p;
                flag=true;
            }
            else{
                flag=false;
                p=1;
            }
        }
        cout << cnt << "\n";
    }
}