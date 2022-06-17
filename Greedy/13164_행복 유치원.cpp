#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> vec;
vector<int> dif;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, k, tmp;
    cin >> n >> k;
    dif.push_back(0);
    for(int i=0;i<n;i++){
        cin >> tmp;
        vec.push_back(tmp);
        if(i) dif.push_back(tmp-vec[i-1]);
    }
    int res=vec[n-1]-vec[0];
    
    sort(dif.begin(), dif.end(), greater<>());

    for(int i=0;i<k-1;i++){
        res-=dif[i];
    }
    cout << res;
}