#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int visited[100001];
int x[3] = {-1, 1, 0};
int xx[3] = {1, 1, 2};
int cnt=0;
int n, k;

void bfs(){
    while(!q.empty()){
        int pre = q.front();
        q.pop();
        if(pre==k){
            break;
        }
        for(int i=0;i<3;i++){
            int now = pre*xx[i]+x[i];
            if(now>=0&&now<=100000&&!visited[now]) {
                q.push(now);
                visited[now]=visited[pre]+1;
            }
        }
    }
}

int main(){
    cin >> n >> k;
    q.push(n);
    bfs();
    cout << visited[k];
}