#include <iostream>
#include <vector>
#include <string>
using namespace std;

string n;
int res;
string str;

void solve(vector<int> vec){
    if(str.length()>0){
        int temp = stoi(str);
        if(temp<=stoi(n))
            res=max(res, temp);
    }

    if(str.length()==n.length()) return;

    for(int i=0;i<vec.size();i++){
        str+=to_string(vec[i]);
        solve(vec);
        str.pop_back();
    }
}

int main(){
    int k, tmp;
    cin >> n >> k;

    vector<int> vec(k);
    for(int i=0;i<k;i++){
        cin >> vec[i];
    }

    solve(vec);
    cout << res;
}