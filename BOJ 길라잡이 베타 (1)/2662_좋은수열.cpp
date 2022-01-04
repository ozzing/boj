#include <iostream>
#include <algorithm>
using namespace std;

int n;
int seq[80];
int min=0xffff;

void dfs(int depth){
    for(int i=1;i<=depth/2;i++){
        // 비교 구간 a~b b~c 일 때 (a, b, b) 또는 (b, c, a)
        if(equal(seq+depth-2*i, seq+depth-i, seq+depth-i)){
            return;
        }
    }

    if(depth==n){
        for(int i=0;i<n;i++) cout << seq[i];
        exit(0);
    }

    for(int i=1;i<=3;i++){
        seq[depth]=i;
        dfs(depth+1);
    }
}

int main(){
    cin >> n;
    dfs(0);
}