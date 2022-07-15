#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str;
vector<pair<int,int>> vec;
bool visited[101]={false,};

void solve(int start, int end, int mid){
    visited[mid]=true;
    for(int i=0;i<str.length();i++){
        if(visited[i]) cout << str[i];
    }
    cout << endl;
    int min=1000, idx=-1;
    for(int i=mid+1;i<end;i++){
        if((int)str[i]<min) {min=str[i]; idx=i;}
    }
    if(!visited[idx] && min != 1000) solve(mid+1, end, idx);
    min=1000;
    for(int i=start;i<mid;i++){
        if((int)str[i]<min) {min=str[i]; idx=i;}
    }
    if(!visited[idx] && min != 1000) solve(start, mid, idx);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> str;

    int len = str.length();    
    for(int i=0;i<len;i++){
        vec.push_back({str[i], i});
    }

    sort(vec.begin(), vec.end());
    solve(0, len, vec[0].second);
}