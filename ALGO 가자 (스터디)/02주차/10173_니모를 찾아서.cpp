#include <iostream>
#include <string>
using namespace std;

int main(){
    while(1){
        int flag=-1;
        string str;
        bool found=false;
        getline(cin, str);
        if(!str.compare("EOI")) break;
        for(int i=0;i<str.size();i++) str[i] = tolower(str[i]);
        flag=str.find("nemo");
        if(flag>=0) cout << "Found\n";
        else cout << "Missing\n";
    }
}