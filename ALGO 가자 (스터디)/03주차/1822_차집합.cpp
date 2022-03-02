#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> s;

int main(){
    int na, nb, tmp;
    cin >> na >> nb;
    for(int i=0;i<na;i++){
        cin >> tmp;
        s.insert(tmp);
    }
    for(int i=0;i<nb;i++){
        cin >> tmp;
        s.erase(tmp);
    }

    cout << s.size() << "\n";
    for(auto iter=s.begin(); iter!=s.end();iter++){
        cout << *iter << " ";
    }
}