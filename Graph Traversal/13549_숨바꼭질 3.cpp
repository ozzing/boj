#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

bool visited[100001];
int n, k;
int pl[3]={0,-1,1};
int mu[3]={2,1,1};

void bfs(){
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    visited[n]=true;
    q.push({0,n});
    while(!q.empty()){
        int depth = q.top().first;
        int loc = q.top().second;
        q.pop();
        if(loc==k){
            cout << depth;
            return;
        }

        for(int i=0;i<3;i++){
            int nloc=loc*mu[i]+pl[i];
            if(nloc<0 || nloc>100000 || visited[nloc]) continue;
            if(i!=0) q.push({depth+1, nloc});
            else q.push({depth, nloc});
            visited[nloc]=true;
        }
    }
}

int main(){
    cin >> n >> k;
    bfs();
}