#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(string a, string b){
    if(a.length() == b.length()){
        return a<b;
    }
    else{
        return a.length()<b.length();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str;
    vector<string> vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>> str;
   //     if(find(vec.begin(), vec.end(), str) == vec.end())
        vec.push_back(str);
    }
    
    sort(vec.begin(), vec.end(), compare);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << endl;
    }
}