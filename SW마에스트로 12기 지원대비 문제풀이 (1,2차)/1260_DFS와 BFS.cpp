#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int map[1001][1001] = {0,};
int visited[1001] = {0,};
int n, m, v;

void dfs(int s){
    visited[s]=1;
    cout << s << " ";
    
    for(int i=1;i<=n;i++){
        if(map[s][i]&&!visited[i]){
            dfs(i);
        }
    }
}

void bfs(){
    queue<int> q;
    q.push(v);
    visited[v]=1;

    while(!q.empty()){
        int s = q.front();
        q.pop();
        cout << s << " ";
        for(int i=1;i<=n;i++){
            if(map[s][i]&&!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

int main(){
    int s, e;
    cin >> n >> m >> v;
    for(int i=0;i<m;i++){
        cin >> s >> e;
        map[s][e]=1;
        map[e][s]=1;
    }

    dfs(v);
    cout << "\n";
    memset(visited, 0, sizeof(visited));
    bfs();
}