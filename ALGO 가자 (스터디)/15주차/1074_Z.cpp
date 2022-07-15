#include <iostream>
#include <cmath>
using namespace std;

long n, r, c;
long res=0;

void solve(int depth, long x, long y){
    if(depth==n) return;
    long size = pow(2, n-depth);
    long half = size/2;
    long block = pow(half, 2);
    if(r<x+half && c<y+half){
        solve(depth+1, x, y);
    }
    else if(r<x+half && c>=y+half){
        res+=block;
        solve(depth+1, x, y+half);
    }
    else if(r>=x+half && c<y+half){
        res+=block*2;
        solve(depth+1, x+half, y);
    }
    else{
        res+=block*3;
        solve(depth+1, x+half, y+half);
    }
}

int main(){
    cin >> n >> r >> c;

    solve(0, 0, 0);

    cout << res;
}