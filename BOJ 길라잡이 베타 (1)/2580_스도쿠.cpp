#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sudoku[9][9];
vector<pair<int,int>> blank;

bool validate(pair<int,int> blank, int n){
    for(int i=0;i<9;i++){
        if(i!=blank.first && sudoku[i][blank.second]==n) return false;
        if(i!=blank.second && sudoku[blank.first][i]==n) return false;
    }
    int x=blank.first/3, y=blank.second/3;
    for(int i=x*3; i<(x+1)*3; i++){
        for(int j=y*3; j<(y+1)*3; j++){
            if(i!=blank.first && j!=blank.second && sudoku[i][j]==n)
                return false;
        }
    }

    return true;
}

void fillin(int n){
    if(n==blank.size()){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<< sudoku[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0);
    }

    for(int i=1;i<=9;i++){
        sudoku[blank[n].first][blank[n].second]=i;
        if(validate(blank[n], i)){
            fillin(n+1);
        }
    }
    sudoku[blank[n].first][blank[n].second]=0;
}

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>> sudoku[i][j];
            if(sudoku[i][j]==0) blank.push_back({i,j});
        }
    }
    fillin(0);
}