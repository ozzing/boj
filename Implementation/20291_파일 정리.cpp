#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> vec;
vector<pair<string,int>> res;

vector<string> split(string str, char delimiter){
    istringstream iss(str);
    string buffer;
    vector<string> result;
    while(getline(iss, buffer, delimiter)){
        result.push_back(buffer);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string str;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        string tmp = split(str, '.')[1];
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());

    int idx=0;
    res.push_back({vec[0], 1});
    for(int i=1;i<vec.size();i++){
        if(vec[i]==res[idx].first){
            res[idx].second++;
        }   
        else{
            idx++;
            res.push_back({vec[i], 1});
        }   
    }

    for(int i=0;i<res.size();i++){
        cout << res[i].first << " " << res[i].second << "\n";
    }
}