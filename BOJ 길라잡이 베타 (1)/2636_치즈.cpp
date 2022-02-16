#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int,int>> q;
int n, m;
int hour=0, cheese=0;
int map[100][100];
bool visited[100][100];
bool check = true;

int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};

bool bfs(){
    int cnt=0;
    while(!q.empty()){
        int prex = q.front().first;
        int prey = q.front().second;
        visited[prex][prey]=true;
        q.pop();

        for(int i=0;i<4;i++){
            int x = prex + dx[i];
            int y = prey + dy[i];
            if(x<0||x>=n||y<0||y>=m||visited[x][y]) continue;
            if(map[x][y]==0){
                q.push({x,y});
            }
            else if(map[x][y]==1){
                map[x][y]=0;
                cnt++;
            }
            visited[x][y]=true;
        }
    }
    if(cnt==0){
        cout << hour << "\n" << cheese;
        return false;
    }
    else{
        cheese = cnt;
        hour++;
        return true;
    }
}


int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];
        }
    }
    while(check){
        q.push({0,0});
        check = bfs();
        memset(visited, false, sizeof(visited));
    }
}