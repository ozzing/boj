#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
bool visited[10001];
vector<int> com[10001];
int n, m, cnt;

void dfs(int num){
    visited[num]=true;
    for(int i=0;i<com[num].size();i++){
        int tmp=com[num][i];
        if(!visited[tmp]){
            dfs(tmp);
            cnt++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int a, b;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        com[b].push_back(a);
    }

    int max=0;
    for(int i=1;i<=n;i++){
        cnt = 0;
        dfs(i);
        if(cnt > max){
            while(!q.empty()) q.pop();
            q.push(i);
            max=cnt;
        }
        else if(cnt==max){
            q.push(i);
        }
        memset(visited, false, sizeof(visited));
    }

    int size=q.size();
    for(int i=0;i<size;i++){
        cout << q.top() << " ";
        q.pop();
    }
}