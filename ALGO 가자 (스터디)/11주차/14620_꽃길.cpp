#include <iostream>
#include <cstring>
using namespace std;

int map[11][11];
int price[11][11]={0,};
bool visited[11][11];

int dx[5]={0,0,1,0,-1};
int dy[5]={0,1,0,-1,0};
int n, ans;

void setTrue(int i, int j){
    for(int d=0;d<5;d++){
        visited[i+dx[d]][j+dy[d]]=true;
    }
}

void setFalse(int i, int j){
    for(int d=0;d<5;d++){
        visited[i+dx[d]][j+dy[d]]=false;
    }
}

void dfs(int sum, int x, int depth){
    if(depth==3){
        ans=min(ans, sum);
        return;
    }

    for(int i=x;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            bool check=true;
            for(int d=0;d<5;d++){
                if(visited[i+dx[d]][j+dy[d]]) check=false;
            }
            if(check) {
                setTrue(i,j);
                dfs(sum+price[i][j], i, depth+1);
                setFalse(i,j);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ans=0xfff;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }

    for(int i=1;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            price[i][j]=map[i][j];
            for(int d=1;d<5;d++){
                price[i][j]+=map[i+dx[d]][j+dy[d]];
            }
        }
    }

    dfs(0, 1, 0);    

    cout << ans;
}