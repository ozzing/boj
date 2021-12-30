#include <iostream>
using namespace std;

int lotto[6];
int arr[16];
int k;

void dfs(int n, int depth){
    if(depth==6){
        for(int i=0;i<6;i++)
            printf("%d ", lotto[i]);
        cout<<"\n";
        return;
    }

    for(int i=n;i<k;i++){
        lotto[depth]=arr[i];
        dfs(i+1, depth+1);
    }    
}

int main(){
    while(1){
        cin >> k;
        if(k==0) break;
        for(int i=0;i<k;i++){
            cin >> arr[i];
        }
        dfs(0, 0);
        cout<< "\n";
    }
}