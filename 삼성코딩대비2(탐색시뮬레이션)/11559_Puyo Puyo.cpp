#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

char field[12][6];
int visited[12][6]={0,};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1 ,0};

bool search(){
    bool check=false;
    for(int i=11;i>=0;i--){
        for(int j=0;j<6;j++){
            if(visited[i][j] || field[i][j]=='.') continue;

            vector<pair<int,int>> vec;
            queue<pair<int,int>> q;
            vec.push_back({i,j});
            q.push({i,j});
            
            while(!q.empty()){
                int x=q.front().first;
                int y=q.front().second;
                visited[x][y]=true;
                q.pop();

                for(int d=0;d<4;d++) {
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    
                    if( visited[nx][ny] || nx<0 || nx>=12 || ny<0 || ny>=6) continue;
                    if(field[nx][ny]==field[x][y]){
                        vec.push_back({nx, ny});
                        q.push({nx, ny});
                    }
                }   
            }
            if(vec.size()>=4){
                for(int v=0;v<vec.size();v++){
                    field[vec[v].first][vec[v].second]='.';
                }
                check=true;
            }
        }
    }
    return check;
}

void drop(){
    for(int j=0;j<6;j++){  
        int flag=11;
        for(int i=11;i>=0;i--){
            if(field[i][j]=='.') continue;
            if(i!=flag){
                field[flag][j]=field[i][j];
                field[i][j]='.';
            }
            flag--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int res=0;
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin >> field[i][j];
        }
    }

    int ans=0;
    while(search()){
        drop();
        ans++;
        memset(visited, false, sizeof(visited));
    }
    cout << ans;
}