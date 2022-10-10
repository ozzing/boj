#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int tmp[8];
int n, m, x;

void solve(int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout << tmp[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0;i<vec.size();i++){
        tmp[depth]=vec[i];
        solve(depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());
    solve(0);
}