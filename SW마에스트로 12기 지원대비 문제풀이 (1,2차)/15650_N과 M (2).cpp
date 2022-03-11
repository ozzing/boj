#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int arr[9];
int n, m;

void solve(int depth){
    if(depth == m) {
        for(int i=0;i<m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=n;i++){
        bool check=true;
        for(int j=0;j<depth;j++){
            if(arr[j]>=i) check = false;
        }
        if(check){
            arr[depth]=i;
            solve(depth+1);
        }
    }
}

int main(){
    cin >> n >> m;
    solve(0);
}