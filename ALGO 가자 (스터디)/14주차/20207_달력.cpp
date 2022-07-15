#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first) return true;
    else if (a.first == b.first){
        if(a.second - a.first > b.second - b.first) return true;
        else return false;
    }
    else return false;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i].first >> vec[i].second;
    }

    sort(vec.begin(), vec.end(), cmp);

    int cnt[366]={0,};
    for(int i=0;i<vec.size();i++){
        for(int j=vec[i].first;j<=vec[i].second;j++){
            cnt[j]++;
        }
    }

    int res=0, height=0, width=0;
    for(int i=1;i<=365;i++){
        if(cnt[i]){
            if(height<cnt[i]) height=cnt[i];
            width++;
            if(i==365) res+=width*height;
        }
        else{
            res+=width*height;
            width=0;
            height=0;
        }
    }

    cout << res;
}