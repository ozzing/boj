#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

#define MAX 1001

int n, m, s, e, f;
vector<pair<int,int>> bus[MAX];
unsigned long long fare[MAX];

void solve(){
    fare[s]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});

    while(!pq.empty()){
        int price = pq.top().first;
        int loc = pq.top().second;
        pq.pop();

        if(price > fare[loc]) continue;

        for(int i=0;i<bus[loc].size();i++){
            int nfare=price+bus[loc][i].second;
            int nloc=bus[loc][i].first;
           
            if(fare[nloc] > nfare){
                fare[nloc]=nfare;
                pq.push({nfare, nloc});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i=0;i<m;i++){
        cin >> s >> e >> f;
        bus[s].push_back({e, f});
    }

    cin >> s >> e;

    memset(fare, 0xffffff, sizeof(fare));
    solve();
    cout << fare[e];
}