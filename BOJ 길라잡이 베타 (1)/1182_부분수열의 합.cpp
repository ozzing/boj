#include <iostream>
#include <algorithm>
using namespace std;

int cnt = 0;
int arr[20];
int res[20];
int n, s;

void dfs(int k, int depth){
    int sum=0;
    for(int i=0;i<depth;i++){
        sum+=res[i];
    }
    if(depth!=0 && sum == s) cnt++;

    for(int i=k;i<n;i++){
        res[depth]=arr[i];
        dfs(i+1, depth+1);
    }    
}

int main(){
    cin >> n >> s;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    dfs(0,0);
    cout<< cnt;
}