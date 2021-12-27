#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x, y;
    vector<pair<int, int>> a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        a.push_back({y, x});
    }

    sort(a.begin(), a.end());

    for(int i=0;i<n;i++){
        cout<< a[i].second << ' ' << a[i].first << '\n';
    }
}