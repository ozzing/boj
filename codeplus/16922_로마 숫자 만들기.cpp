#include <iostream>
#include <set>
using namespace std;

int arr[4]={1,5,10,50};
int n;
set<int> s;

void solve(int prev, int depth, int sum){
    if(depth==n){
        s.insert(sum);
        return;
    }

    for(int i=prev;i<4;i++){
        solve(i, depth+1, sum+arr[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    solve(0, 0, 0);

    cout << s.size();
}