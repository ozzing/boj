#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<string> vec;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string str;
    cin >> str;

    char s[1005];
    strcpy(s, str.c_str());
    char* ptr=s;
    for(int i=0;i<str.length();i++){
        string tmp(ptr);
        vec.push_back(tmp);
        ptr++;
    }

    sort(vec.begin(), vec.end());
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << "\n";
    }
}