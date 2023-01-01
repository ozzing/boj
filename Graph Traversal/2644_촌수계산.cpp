#include <iostream>
#include <queue>
using namespace std;

bool arr[105][105];
bool visited[105];

int bfs(int a, int b){
    int res=-1;

    queue<pair<int,int>> q;
    q.push({a, 0});

    while(!q.empty()){
        int now=q.front().first;
        int depth=q.front().second;
        q.pop();

        if(now==b) return depth;

        for(int i=1;i<=100;i++){
            if(visited[i] || !arr[now][i]) continue;
            visited[i]=true;
            q.push({i, depth+1});
        }
    }


    return res;
}

int main(){
    int n, m, a, b, x, y;
    cin >> n >> a >> b >> m;

    for(int i=0;i<m;i++){
        cin >> x >> y;
        arr[x][y]=true;
        arr[y][x]=true;
    }

    int res=bfs(a, b);

    cout << res;
}