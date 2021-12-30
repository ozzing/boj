#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt=0;
int chess[15]={0};
bool check;

void nqueen(int num){
    if(num==n) {cnt++; return;}

    for(int i=0;i<n;i++){
        chess[num]=i;
        check=true;
        for(int j=0;j<num;j++){
            if(chess[num] == chess[j] || (num-j) == abs(chess[num] - chess[j])){
                check=false;
                break;
            }
        }
        if(check){
            nqueen(num+1);
        }

    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        chess[0]=i;
        nqueen(1);
    }
    cout << cnt;
}