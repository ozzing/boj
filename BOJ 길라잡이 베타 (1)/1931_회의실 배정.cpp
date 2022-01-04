#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> time;

int main(){
    int n, s, e;
    int cnt=1;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s >> e;
        time.push_back({e, s});
    }
    sort(time.begin(), time.end());

    int num=time[0].first;
    for(int i=1;i<n;i++){
        if(time[i].second>=num){
            cnt++;
            num=time[i].first;
        }
    }

    cout << cnt;
}