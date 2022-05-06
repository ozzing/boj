#include <iostream>
using namespace std;

int n, m, u, v, cnt;
int graph[1001][1001];
bool visited[1001];

void dfs(int val){
    for(int i=1;i<=n;i++){
        if(i!=val && !visited[i] && graph[val][i]==1){
            visited[i]=true;
            dfs(i);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    cnt=0;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        graph[u][v]=1;
        graph[v][u]=1;
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i]=true;
            dfs(i);
            cnt++;
        }
    }
    
    cout << cnt;
}