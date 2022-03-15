#include <iostream>
#include <cstring>
using namespace std;

int board[5][5];
pair<int,int> loc[26];

bool bingo(){
    int cnt=0;
    bool b[4];

    memset(b, true, sizeof(b));
    for(int i=0;i<5;i++){
        b[0]=true; b[1]=true;
        for(int j=0;j<5;j++){
            if(board[i][j]!=0) b[0]=false;
            if(board[j][i]!=0) b[1]=false;
        }
        for(int j=0;j<2;j++){
            if(b[j]) cnt++;
        }
        if(board[i][i]!=0) b[2]=false;
        if(board[i][4-i]!=0) b[3]=false;
    }
    for(int j=2;j<4;j++){
        if(b[j]) cnt++;
    }
    if(cnt>=3) return true;
    else return false;
}

int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> board[i][j];
            loc[board[i][j]]={i,j};
        }
    }

    int tmp;
    for(int t=0;t<25;t++){
        cin >> tmp;
        board[loc[tmp].first][loc[tmp].second]=0;
        if(t>=10 && bingo()) {
            cout << t+1;
            break;
        }
    }
}