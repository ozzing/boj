#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> str;
vector<string> res;

vector<string> split(string s, char delimiter){
    istringstream iss(s);
    vector<string> result;
    string buffer;

    while(getline(iss, buffer, delimiter)){
        result.push_back(buffer);
    }
    return result;
}

int main(){
    string s, tmp="";
    getline(cin, s);
    for(int i=0;i<s.length();i++){
        if(s[i]=='<'){
            if(tmp!="") {
                str.push_back(tmp);
            }
            tmp=s[i];
        }
        else if(s[i]=='>'){
            tmp+=s[i];
            str.push_back(tmp);
            tmp="";
        }
        else{
            tmp+=s[i];
        }
    }
    if(tmp!="") {
        str.push_back(tmp);
    }
    for (int i=0;i<str.size();i++){
        vector<string> temp = split(str[i], ' ');
        if(str[i][0]=='<'){
            cout << str[i];
        }
        else{
        for(int j=0;j<temp.size();j++){
                reverse(temp[j].begin(), temp[j].end());
                cout << temp[j];
                if(j!=temp.size()-1) cout << " ";
            }
        }
    }


    // res = split(s, ' ');
    // for(int i=0;i<res.size();i++){
    //     reverse(res[i].begin(), res[i].end());
    //     cout << res[i] << " ";
    // }
}