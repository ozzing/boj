#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n;
    char tmp, val;
    string str;
    stack <char> left;
    stack <char> right;
    cin >> str;
    cin >> n;
    for(int i=0;i<str.size();i++){
        left.push(str[i]);
    }
    
    for(int i=0;i<n;i++){
        cin>> tmp;
        if(tmp == 'L'){
            if(!left.empty()){
                tmp=left.top();
                left.pop();
                right.push(tmp);
            }
        }
        else if(tmp == 'D'){
            if(!right.empty()){
                tmp=right.top();
                right.pop();
                left.push(tmp);
            }
        }
        else if(tmp == 'B'){
            if(!left.empty()){
                left.pop();
            }   
        }
        else if(tmp == 'P'){
            cin>> val;
            left.push(val);   
        }
    }

    while(!left.empty()){
        tmp=left.top();
        left.pop();
        right.push(tmp);
    }

    while(!right.empty()){
        tmp=right.top();
        cout<<tmp;
        right.pop();
    }
}
