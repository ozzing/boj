#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;
int res;

void solve(string str){
    if(str.length()==s.length()){
        if(!str.compare(s)){
            res=1;
        }
        return;
    }

    string temp=str;
    if(temp[str.length()-1]=='A'){
        temp.pop_back();
        solve(temp);
        temp=str;
    }
    if(temp[0]=='B'){
        temp.erase(0, 1);
        reverse(temp.begin(), temp.end());
        solve(temp);

    }
}

int main(){
    cin >> s;
    cin >> t;

    res=0;
    solve(t);

    cout << res;
}