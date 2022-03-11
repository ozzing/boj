#include <iostream>
using namespace std;

int chess[16];
int n, cnt=0;

void nqueen(int depth){
    if(depth==n+1){
        cnt++; return;
    }
    
    for(int i=1;i<=n;i++){
        bool check=true;
        chess[depth]=i;
        for(int j=1;j<depth;j++){
            if(chess[depth]==chess[j] || abs(chess[depth]-chess[j])==abs(depth-j)){
                 check=false;
                 break;
            }
        }
        if(check) nqueen(depth+1);
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        chess[1]=i;
        nqueen(2);
    }
    cout << cnt;
}