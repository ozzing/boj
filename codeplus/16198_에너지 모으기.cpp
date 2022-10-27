#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int ans;

void dfs(vector<int> vec, int sum){
    if(vec.size()==2){
        ans=max(sum, ans);
        return;
    }

    for(int i=1;i<vec.size()-1;i++){
        vector<int> tmp=vec;
        tmp.erase(tmp.begin()+i);
        dfs(tmp, sum+vec[i-1]*vec[i+1]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, w;
    cin >> n;
    
    vector<int> vec;
    for(int i=0;i<n;i++){
        cin >> w;
        vec.push_back(w);
    }

    dfs(vec, 0);
    cout << ans;
}