#include <iostream>
#include <string>
using namespace std;

int main(){
    int ascii=97;
    string s;
    cin >> s;
    while(ascii<=122){
        int check=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]==ascii){
                check=i;
                break;
            }
        }
        cout << check << " ";
        ascii++;
    }
}