#include <iostream>
using namespace std;

int map[999][999];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;

    int x = n/2;
    int y = x;
    int num = 1;
    int dir = 0, side = 0, cnt=0, check=1;
    int resx, resy;
    while(num<=n*n){
        map[x][y]=num++;
        if(num-1==k){resx=x;resy=y;}
        x+=dx[dir]; y+=dy[dir];
        cnt++;
        if(cnt==check) {
            cnt=0;
            dir++;
            side++;
            if(dir==4) dir=0;
            if(side==2) {
                check++;
                side=0;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }   
    cout << resx+1 << " " << resy+1;
}