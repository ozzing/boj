#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100001

int n, k, cnt;
short pl[3]={-1,1,0};
short mu[3]={1,1,2};
bool visited[MAX] = {false,};
int parent[MAX];
vector<int> ans;

void bfs(){
    queue<pair<unsigned int, unsigned int>> q; 
    q.push({n, 0});
    visited[n]=true;

    while(!q.empty()){
        int loc = q.front().first;
        int sec = q.front().second;
        q.pop();

        if(loc==k){
            cout << sec << "\n" << n << " ";
            while(loc!=n){
                ans.push_back(loc);
                loc=parent[loc];
            }
            break;
        }

        for(int i=0;i<3;i++){
            int nloc = mu[i]*loc + pl[i];
            if(nloc>=0 && nloc<MAX && !visited[nloc]){
                visited[nloc]=true;
                parent[nloc]=loc;
                q.push({nloc, sec+1});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    bfs();
    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << " ";
    }
}