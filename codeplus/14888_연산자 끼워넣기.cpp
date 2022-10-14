#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[12];
int n;
int op[4];
vector<long long> res;

void solve(int depth, int sum){
    if(depth==n) {
        res.push_back(sum);
        return;
    }

    int tmp = arr[depth];
    for(int i=0;i<4;i++){
        if(op[i]>0){
            op[i]--;

            if(i==0) solve(depth+1, sum+tmp);
            if(i==1) solve(depth+1, sum-tmp);
            if(i==2) solve(depth+1, sum*tmp);
            if(i==3) solve(depth+1, sum/tmp);
            
            op[i]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<4;i++){
        cin >> op[i];
    }

    solve(1, arr[0]);

    sort(res.begin(), res.end());

    cout << res[res.size()-1] << "\n";
    cout << res[0] << "\n";
}