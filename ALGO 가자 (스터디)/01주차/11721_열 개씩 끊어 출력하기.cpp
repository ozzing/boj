#include <iostream>
#include <string>
using namespace std;

int main(){
    int start=0;
    string str;
    cin >> str;
    while(str.size()>start){
        cout << str.substr(start, 10) << endl;
        start+=10;
    }
}