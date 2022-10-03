#include <iostream>
#include <vector>
using namespace std;
#define MAX 102

int height[MAX][MAX];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, h;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> height[i][j];
        }
    }

    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int d=0;d<4;d++){
                int nx=i+dx[d];
                int ny=j+dy[d];

                if(height[nx][ny]<height[i][j]){
                    res+=height[i][j]-height[nx][ny];
                }
           }
        }
    }

    res+=2*n*m;
    cout << res;
}

