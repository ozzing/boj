#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t, n, size;
    char tr;
    bool rev, err;
    cin >> t;
    for(int i=0;i<t;i++){
        deque<int> dq;
        string p, input;
        rev=false;
        err=false;
        cin >> p;
        cin >> n;
        cin >> input;
        string tmp="";
        if(n!=0){
            for(int j=0;j<input.length();j++){
                if(input[j]=='[' || input[j]==']' || input[j]==','){
                    if(input[j]!='[') dq.push_back(stoi(tmp));
                    tmp="";
                    continue;
                }
                tmp+=input[j];
            }
        }
        for(int j=0;j<p.length();j++){
            if(p[j]=='R'){
               rev=!rev;
            }
            if(p[j]=='D'){
                if(dq.size()!=0){
                    if(rev) dq.pop_back();
                    else dq.pop_front();
                }
                else{
                    cout<<"error\n";
                    err=true;
                    break;
                }
            }
        }
        if(!err){
            cout<<"[";
            if(rev){
                while(!dq.empty()){
                    if(dq.size()!=1) cout<< dq.back()<<",";
                    else cout<< dq.back();
                    dq.pop_back();
                }
            }
            else{
                while(!dq.empty()){
                    if(dq.size()!=1) cout<< dq.front()<<",";
                    else cout << dq.front();
                    dq.pop_front();
                }
            } 
        cout<<"]\n";
        }
    }
}