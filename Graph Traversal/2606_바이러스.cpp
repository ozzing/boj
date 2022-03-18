#include <iostream>
using namespace std;
int com[101][101];
int visited[101];
int n, k, cnt;
void dfs(int num){
    for(int i=1;i<=n;i++){
        if(!visited[i] && com[num][i]){
            visited[i]=1;
            dfs(i);
            cnt++;
        }
    }
}
int main(){
    cnt=0;
    int a, b;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        cin >> a >> b;
        com[a][b]=1;
        com[b][a]=1;
    }
    visited[1]=1;
    dfs(1);
    cout << cnt;
}