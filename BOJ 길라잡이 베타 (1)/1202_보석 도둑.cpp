#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


priority_queue<long long> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> q;
    vector<int> w;
    long long n, k, m, v, c, sum=0, idx=0;

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> m >> v;
        q.push_back({m, v});
    }
    for(int i=0;i<k;i++){
        cin >> c;
        w.push_back(c);
    }

    sort(q.begin(), q.end());
    sort(w.begin(), w.end());

    for(int i=0;i<k;i++){
        while(idx<n && q[idx].first<=w[i]){
            long long temp = q[idx++].second;
            pq.push(temp);
        }
        if(!pq.empty()){
            sum+=(long long)pq.top();
            pq.pop();
        }
    }
    
    cout << sum;
}