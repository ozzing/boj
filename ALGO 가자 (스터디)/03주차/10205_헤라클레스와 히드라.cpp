#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int k, h, s=1;
    cin >> k;
    for(int t=0;t<k;t++){
        cin >> h >> str;
        for(int i=0;i<str.size();i++){
            if(str[i]=='c') h++;
            if(str[i]=='b') h--;       
        }

        printf("Data Set %d:\n%d\n\n", s++, h);
    }
}