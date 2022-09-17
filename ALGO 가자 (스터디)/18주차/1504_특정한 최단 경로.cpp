#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;
#define MAX 805
#define INF 0xffffff

int n, e, a, b, c, v1, v2;
vector<pair<int,int>> node[MAX];
unsigned long long dist[MAX];

void solve(int start){
    for (int i=0;i<=n;i++) dist[i] = INF;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    dist[start]=0;

    while(!pq.empty()){
        int dis=pq.top().first;
        int loc=pq.top().second;
        pq.pop();
        
        for(auto next: node[loc]){
            int ndis = next.second + dis;
            int nloc = next.first;

            if(ndis < dist[nloc]){
                dist[nloc]=ndis;
                pq.push({ndis, nloc});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> e;
    for(int i=0;i<e;i++){
        cin >> a >> b >> c;
        node[a].push_back({b, c});
        node[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    solve(1);
    int one_v1 = dist[v1];
    int one_v2 = dist[v2];

    solve(v1);
    int v1_v2 = dist[v2];
    int v1_n = dist[n];

    solve(v2);
    int v2_n = dist[n];

    int ans = INF;
    ans=min(ans, one_v1 + v1_v2 + v2_n);
    ans=min(ans, one_v2 + v1_v2 + v1_n);
    if(ans==INF || v1_v2==INF) cout << -1;
    else cout << ans;
}