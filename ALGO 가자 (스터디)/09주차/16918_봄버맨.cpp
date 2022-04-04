#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int>> q;
char board[200][200];
int r, c, n;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]=='O') q.push({i,j});
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            board[i][j]='O';
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        board[x][y]='.';

        for(int d=0;d<4;d++){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
            board[nx][ny]='.';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> n;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> board[i][j];
            if(board[i][j]=='O') q.push({i,j});
        }
    }
   
    for(int t=2;t<=n;t+=2){
        solve();    
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(n%2==0) cout << "O";
            else cout << board[i][j];
        }
        cout << "\n";
    }
}