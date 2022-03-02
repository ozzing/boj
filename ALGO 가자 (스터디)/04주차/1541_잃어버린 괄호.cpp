#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> num;
vector<char> sign;

int main(){
    string str, tmp="";
    cin >> str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='+'||str[i]=='-'){
            sign.push_back(str[i]);
            num.push_back(atoi(tmp.c_str()));
            tmp="";
        }
        else{
            tmp+=str[i];
        }
    }            
    num.push_back(atoi(tmp.c_str()));

    int gsum=num[0], lsum=0;
    for(int i=sign.size()-1;i>=0;i--){
        lsum+=num[i+1];
        if(sign[i]=='-'){
            gsum-=lsum;
            lsum=0;
        }
    }
    gsum+=lsum;
    
    cout << gsum;
}