#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int map[25][25];
int visited[25][25]={0,};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n, num;

void dfs(int prex, int prey){
    num++;
    visited[prex][prey]=1;
    for(int i=0;i<4;i++){
        int x = prex+dx[i];
        int y = prey+dy[i];    
        if(map[x][y]&&!visited[x][y]&&x>=0&&x<n&&y>=0&&y<n){
            visited[x][y]=1;
            dfs(x,y);
        }
    }
}
    
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]&&!visited[i][j]){
                num = 0;
                dfs(i, j);
                vec.push_back(num);
            }
        }
    }
    sort(vec.begin(), vec.end());
    cout << vec.size() << "\n";
    for(int i=0;i<vec.size();i++) cout << vec[i] << "\n";
}