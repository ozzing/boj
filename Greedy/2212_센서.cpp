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
    cin >> n;
    cin >> k;

    for(int i=0;i<n;i++){
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());

    long res=0;
    for(int i=1;i<vec.size();i++){
        int diff=vec[i]-vec[i-1];
        dif.push_back(diff);
        res+=diff;
    }

    sort(dif.begin(), dif.end(), greater<>());
   
    if(dif.size()<k-1){cout << 0; return 0;}

    for(int i=0;i<k-1;i++){
        res-=dif[i];
    }

    cout << res;
}