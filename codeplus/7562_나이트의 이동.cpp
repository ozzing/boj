#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int test, l, x1, y1, x2, y2;

int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};
bool visited[301][301];

void bfs(){
    queue<pair<pair<int,int>,int>> q;
    q.push({{x1, y1}, 0});
    visited[x1][y1]=true;

    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int cnt=q.front().second;
        q.pop();
        if(x==x2 && y==y2){
            cout << cnt << endl;
            return;
        }
         
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0 || nx>=l || ny<0 || ny>=l || visited[nx][ny]) continue;

            q.push({{nx, ny}, cnt+1});
            visited[nx][ny]=true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> test;
    for(int t=0;t<test;t++){
        cin >> l;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        memset(visited, false, sizeof(visited));
        bfs();
    }
}