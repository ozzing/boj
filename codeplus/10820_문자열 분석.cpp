#include <iostream>
using namespace std;

int main(){
    string str;
    
    while(getline(cin, str)){
        if(str.length()==0) break;
        int big=0, small=0, num=0, blank=0;
        for(int i=0;i<str.length();i++){
            if(str[i]>='A' && str[i]<='Z') big++;
            if(str[i]>='a' && str[i]<='z') small++;
            if(str[i]>='0' && str[i]<='9') num++;
            if(str[i]==' ') blank++;
        }
        cout << small << " " << big << " " << num << " " << blank << "\n";
    }
}