#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m;
int *arr;
bool *visited;

void solve(int depth, string str){
    if(depth==m){
        cout << str << "\n";
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            solve(depth+1, str+" "+to_string(arr[i]));
            visited[i]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    arr = new int[n];
    visited = new bool[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i=0;i<n;i++){
        visited[i]=true;
        solve(1, to_string(arr[i]));
        visited[i]=false;
    }

    free(arr);
    free(visited);
}