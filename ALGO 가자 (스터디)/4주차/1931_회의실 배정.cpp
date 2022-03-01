#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> time;

int main(){
    int n, s ,e;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s >> e;
        time.push_back({e,s});
    }
    sort(time.begin(), time.end());

    int end = time[0].first, cnt=1;
    for(int i=1;i<n;i++){
        if(time[i].second>=end){
            end=time[i].first;
            cnt++;
        }
    }
    cout << cnt;
}