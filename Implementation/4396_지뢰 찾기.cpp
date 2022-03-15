#include <iostream>
using namespace std;

int in[10][10];
int n;
int dx[8] = {0,1,0,-1,-1,1,-1,1};
int dy[8] = {1,0,-1,0,-1,-1,1,1};

void get_number(int x, int y){
    int cnt=0;
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<n&&in[nx][ny]%2==1) cnt++;
    }
    cout << cnt;
}

int main(){
    bool check=false;
    char c;
    cin >> n;
    getchar();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> c;
            if(c=='*') in[i][j]=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> c;
            if(c=='x') in[i][j]+=2;
            if(in[i][j]==3) check=true;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(check){
                if(in[i][j]%2==1) cout << "*";
            }
            else{
                if(in[i][j]%2==1) cout << ".";
            }
            
            if(in[i][j]==2) get_number(i, j);
            else if(in[i][j]==0) cout << ".";
        }
        cout << "\n";
    }   
}