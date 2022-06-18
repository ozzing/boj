#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<pair<int,int>> vec;
    int n, s, e;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s >> e;
        vec.push_back({s, 1});
        vec.push_back({e, -1});
    }

    sort(vec.begin(), vec.end());

    int cnt=0, maxi=0;
    for(int i=0;i<vec.size();i++){
        cnt+=vec[i].second;
        maxi=max(maxi, cnt);
    }

    cout << maxi;
}