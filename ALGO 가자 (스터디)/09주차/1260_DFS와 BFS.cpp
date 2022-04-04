#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<int> q;
bool visited[1001]={false,};
int arr[1001][1001];
int n, m, v;

void dfs(int point){
    visited[point]=true;
    cout << point << " ";
    for(int i=1;i<=n;i++){
        if(!visited[i] && arr[point][i]){
            dfs(i);
        }
    }
}

void bfs(){
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cout << tmp << " ";

        for(int i=1;i<=n;i++){
            if(!visited[i] && arr[tmp][i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }
}

int main(){
    int a, b;
    cin >> n >> m >> v;

    for(int i=0;i<m;i++){
        cin >> a >> b;
        arr[a][b]=1;
        arr[b][a]=1;
    }

    dfs(v);
    cout << "\n";

    memset(visited, false, sizeof(visited));
    q.push(v);
    visited[v]=true;
    bfs();
}