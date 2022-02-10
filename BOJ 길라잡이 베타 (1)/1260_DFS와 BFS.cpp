#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 1001
int map[MAX][MAX] = {0,};
bool visited[MAX] = {false,};
int n, m, v;

void dfs(int v){
    visited[v] = true;
    cout << v << " ";

    for (int i = 1; i <= n; i++){
        if (map[v][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v] = true;
    cout << v << " ";

    while (!q.empty()){
        int from = q.front();
        q.pop();

        for (int i = 1; i <= n; i++){
            if (map[from][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = true;
                cout << i << " ";
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++){
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    
    dfs(v);
    cout << endl;
    for (int i = 0; i < MAX; i++) visited[i] = false;
    bfs(v);
}