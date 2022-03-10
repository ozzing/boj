#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> vec;
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
        bool check=false;
        for(int j=0;j<depth;j++){
            if(arr[j]==i) check = true;
        }
        if(!check){
            arr[depth]=i;
            solve(depth+1);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) vec.push_back(i);

    solve(0);
}