#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    string line;

    cin >> t;

    cin.ignore();
    for(int i=0;i<t;i++){
        char str[1005];
        getline(cin, line);
        strcpy(str, line.c_str());
        
        char* ptr = strtok(str, " ");
        while(ptr!=NULL){
            string tmp(ptr);
            reverse(tmp.begin(), tmp.end());
            cout << tmp << " ";
            ptr = strtok(NULL,  " ");
        }
        cout << "\n";
    }
}