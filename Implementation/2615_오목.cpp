#include <iostream>
using namespace std;

int board[23][23];
int dx[4] = {-1,0,1,1};
int dy[4] = {1,1,1,0};

int solve(int x, int y, int num){
    for(int d=0;d<4;d++){
        int nx=x, ny=y;
        bool check = true;
        if(x-dx[d]<0||y-dy[d]<0||x-dx[d]>19||y-dy[d]>19||board[x-dx[d]][y-dy[d]]!=num){
            for(int k=0;k<6;k++){
                if(board[nx][ny]!=num&&k<5){
                    check = false;
                    break;
                }
                else if(board[nx][ny]==num&&k==5){
                    check = false;
                    break;
                }
                nx+=dx[d]; ny+=dy[d];
            }
            if(check){
                cout << num << "\n" << x+1 << " " << y+1;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cin >> board[i][j];
        }
    }

    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            if(board[i][j]==1 || board[i][j]==2) {
                if(solve(i, j, board[i][j])) return 0;
            }
        }
    }
    cout << 0;
}