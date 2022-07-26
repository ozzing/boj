#include <iostream>
#include <cstring>
using namespace std;

int r, c, t, top, bot;
int mat[52][52];
int tmp[52][52];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void diffuse(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]>0){
                int pivot = mat[i][j]/5;
                
                int cnt=0;
                for(int d=0;d<4;d++){
                    int nx=i+dx[d];
                    int ny=j+dy[d];
                    
                    if(mat[nx][ny]==-1 || nx<0 || nx>=r || ny<0 || ny>=c) continue;
                    tmp[nx][ny]+=pivot;
                    cnt++;
                }
                
                tmp[i][j]-=pivot*cnt;
            }
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            mat[i][j]+=tmp[i][j];
        }
    }
}

void blow(){
    for(int i=top;i>0;i--){
        mat[i][0]=mat[i-1][0];
    }
    for(int i=0;i<c-1;i++){
        mat[0][i]=mat[0][i+1];
    }
    for(int i=0;i<top;i++){
        mat[i][c-1]=mat[i+1][c-1];
    }
    for(int i=c-1;i>1;i--){
        mat[top][i]=mat[top][i-1];
    }
    mat[top][1]=0;
    mat[top][0]=-1;
    for(int i=bot;i<r-1;i++){
        mat[i][0]=mat[i+1][0];
    }
    for(int i=0;i<c-1;i++){
        mat[r-1][i]=mat[r-1][i+1];
    }
    for(int i=r-1;i>bot;i--){
        mat[i][c-1]=mat[i-1][c-1];
    }
    for(int i=c-1;i>0;i--){
        mat[bot][i]=mat[bot][i-1];
    }
    mat[bot][1]=0;
    mat[bot][0]=-1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> r >> c >> t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mat[i][j];
            if(mat[i][j]==-1){
                bot=i;
            }
        }
    }
    top=bot-1;

    for(int k=0;k<t;k++){
        memset(tmp, 0, sizeof(tmp));
        diffuse();
        blow();
    }

    long ans=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mat[i][j]>0) ans+=mat[i][j];
        }
    }
    cout << ans;
}