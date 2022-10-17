#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int arr[22];
bool check[2000005];
int n;
set<int> s;

void solve(int sum, int depth){
    
    if(depth==n){
        check[sum]=true;
        return;
    }
    else{
        solve(sum, depth+1);
        solve(sum+arr[depth], depth+1);
    }
}

int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    solve(0, 0);

    long long res=1;
    while(check[res]) res++;
    cout << res;
}