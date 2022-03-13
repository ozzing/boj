#include <iostream>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    pair<int,int> gas[10000];
    priority_queue<int> pq;
    int n, l, p;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> gas[i].first >> gas[i].second;
    }
    cin >> l >> p;
    sort(gas, gas+n);

    int cnt=0, i=0;
    while(p<l){
        while(i<n && gas[i].first <= p){
            pq.push(gas[i].second);
            i++;
        }
        if(pq.empty()){
            cout << -1;
            return 0;
        }
        p += pq.top();
        pq.pop();
        cnt++;
    }
    cout << cnt;
}