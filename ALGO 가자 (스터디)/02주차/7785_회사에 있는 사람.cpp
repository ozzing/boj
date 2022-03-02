#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string name, cmd;
        cin >> name >> cmd;
        if(!cmd.compare("enter")) s.insert(name);
        if(!cmd.compare("leave")) s.erase(name);
    }
    for(auto iter=s.rbegin();iter!=s.rend();iter++){
        cout << *iter << "\n";
    }
}